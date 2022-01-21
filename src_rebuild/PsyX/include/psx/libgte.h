#ifndef LIBGTE_H
#define LIBGTE_H

#include "types.h"
#include "PsyX/common/pgxp_defs.h"

typedef struct {
	short	m[3][3];	/* 3x3 rotation matrix */
	long    t[3];		/* transfer vector */
} MATRIX;

typedef struct {		/* long word type 3D vector */
	long	vx, vy;
	long	vz, pad;
} VECTOR;

struct SVECTOR {		/* short word type 3D vector */
	short	vx, vy;
	short	vz, pad;
};

struct CVECTOR {		/* color type vector */
	unsigned char	r, g, b, cd;
};

typedef struct {		/* 2D short vector */
	short vx, vy;
} DVECTOR;

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif

extern void InitGeom();
extern void SetGeomOffset(int ofx, int ofy);
extern void SetGeomScreen(int h);

extern void SetRotMatrix(MATRIX* m);
extern void SetLightMatrix(MATRIX* m);
extern void SetColorMatrix(MATRIX* m);
extern void SetTransMatrix(MATRIX* m);
extern void PushMatrix();
extern void PopMatrix();
VECTOR *ApplyMatrix(MATRIX *m, SVECTOR *v0, VECTOR *v1);
VECTOR *ApplyRotMatrix(SVECTOR *v0, VECTOR *v1);
VECTOR *ApplyRotMatrixLV(VECTOR *v0, VECTOR *v1);
SVECTOR *ApplyMatrixSV(MATRIX *m, SVECTOR *v0, SVECTOR *v1);
VECTOR *ApplyMatrixLV(MATRIX *m, VECTOR *v0, VECTOR *v1);
extern void RotTrans(struct SVECTOR* v0, VECTOR* v1, long* flag);
extern void RotTransSV(SVECTOR* v0, SVECTOR* v1, long* flag);
extern long RotTransPers(struct SVECTOR* v0, long* sxy, long* p, long* flag);
extern long RotTransPers3(SVECTOR* v0, SVECTOR* v1, SVECTOR* v2, long* sxy0, long* sxy1, long* sxy2, long* p, long* flag);
extern long RotTransPers4(SVECTOR* v0, SVECTOR* v1, SVECTOR* v2, SVECTOR* v3, long* sxy0, long* sxy1, long* sxy2, long* sxy3, long* p, long* flag);
extern void NormalColor(SVECTOR* v0, CVECTOR* v1);
extern void NormalColor3(SVECTOR* v0, SVECTOR* v1, SVECTOR* v2, CVECTOR* v3, CVECTOR* v4, CVECTOR* v5);
extern void NormalColorDpq(struct SVECTOR* v0, struct CVECTOR* v1, long p, struct CVECTOR* v2);
extern void NormalColorCol(struct SVECTOR* v0, struct CVECTOR* v1, struct CVECTOR* v2);
extern void NormalColorCol3(SVECTOR* v0, SVECTOR* v1, SVECTOR* v2, CVECTOR* v3, CVECTOR* v4, CVECTOR* v5, CVECTOR* v6);
extern void LocalLight(SVECTOR* v0, VECTOR* v1);
extern long RotAverageNclip4(struct SVECTOR* v0, struct SVECTOR* v1, struct SVECTOR* v2, struct SVECTOR* v3, long* sxy0/*arg_10*/, long* sxy1/*arg_14*/, long* sxy2/*arg_18*/, long* sxy3/*arg_1C*/, long* p/*arg_20*/, long* otz/*arg_24*/, long* flag/*arg_28*/);
extern MATRIX* MulMatrix0(MATRIX* m0, MATRIX* m1, MATRIX* m2);
extern MATRIX* MulMatrix(MATRIX* m0, MATRIX* m1);
extern MATRIX* MulMatrix2(MATRIX* m0, MATRIX* m1);
extern void SetBackColor(long rbk, long gbk, long bbk);
extern void SetFarColor(long rfc, long gfc, long bfc);
extern MATRIX* RotMatrix(struct SVECTOR* r, MATRIX* m);
extern MATRIX* RotMatrixYXZ(struct SVECTOR* r, MATRIX* m);
extern MATRIX* RotMatrixZYX_gte(struct SVECTOR* r, MATRIX* m);
extern MATRIX* RotMatrixX(long r, MATRIX *m);
extern MATRIX* RotMatrixY(long r, MATRIX *m);
extern MATRIX* RotMatrixZ(long r, MATRIX *m);
extern MATRIX* TransMatrix(MATRIX* m, VECTOR* v);
extern MATRIX* ScaleMatrix(MATRIX* m, VECTOR* v);
extern MATRIX* MulRotMatrix(MATRIX* m0);
extern void ColorDpq(VECTOR* v0, CVECTOR* v1, long p, CVECTOR* v2);
extern void ColorCol(VECTOR* v0, CVECTOR* v1, CVECTOR* v2);
extern long NormalClip(long sxy0, long sxy1, long sxy2);
extern void SetDQA(int iDQA);
extern void SetDQB(int iDQB);
extern void SetFogNear(long a, long h);
extern void SetFogNearFar(long a, long b, long h);
extern long SquareRoot0(long a);

extern int rsin(int a);
extern int rcos(int a);
extern long ratan2(long y, long x);

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
}
#endif

#endif