#include "cbase.h"
#include "bone_setup.h"

//-----------------------------------------------------------------------------
// Purpose: Realign the matrix so that its X axis points along the desired axis.
//-----------------------------------------------------------------------------
void Studio_AlignIKMatrix(matrix3x4_t &mMat, const Vector &vAlignTo)
{
	Vector tmp1, tmp2, tmp3;

	// Column 0 (X) becomes the vector.
	tmp1 = vAlignTo;
	VectorNormalize(tmp1);
	MatrixSetColumn(tmp1, 0, mMat);

	// Column 1 (Y) is the cross of the vector and column 2 (Z).
	MatrixGetColumn(mMat, 2, tmp3);
	tmp2 = tmp3.Cross(tmp1);
	VectorNormalize(tmp2);
	// FIXME: check for X being too near to Z
	MatrixSetColumn(tmp2, 1, mMat);

	// Column 2 (Z) is the cross of columns 0 (X) and 1 (Y).
	tmp3 = tmp1.Cross(tmp2);
	MatrixSetColumn(tmp3, 2, mMat);
}

