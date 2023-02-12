#include <memory.h>
#include <QDebug>
#include "CameraSimple.h"

static GLfloat cameraVertices[] = {
	0.500000f, -0.350000f, 0.000000f, 0.500000f, -0.350000f, 0.000000f, 0.500000f, -0.350000f, 0.000000f,
	-0.500000f, -0.350000f, 0.000000f, -0.500000f, -0.350000f, 0.000000f,
	-0.500000f, -0.350000f, 0.000000f, -0.500000f, 0.350000f, 0.000000f,
	-0.500000f, 0.350000f, 0.000000f, -0.500000f, 0.350000f, 0.000000f,
	0.500000f, 0.350000f, 0.000000f, 0.500000f, 0.350000f, 0.000000f,
	0.500000f, 0.350000f, 0.000000f, -0.500000f, 0.350000f, 0.300000f,
	-0.500000f, 0.350000f, 0.300000f, -0.500000f, 0.350000f, 0.300000f,
	0.500000f, 0.350000f, 0.300000f, 0.500000f, 0.350000f, 0.300000f,
	0.500000f, 0.350000f, 0.300000f, -0.500000f, -0.350000f, 0.300000f,
	-0.500000f, -0.350000f, 0.300000f, -0.500000f, -0.350000f, 0.300000f,
	0.500000f, -0.350000f, 0.300000f, 0.500000f, -0.350000f, 0.300000f,
	0.500000f, -0.350000f, 0.300000f, -0.285317f, 0.0927050f, 0.000000f,
	-0.242705f, 0.176336f, 0.000000f, -0.242705f, 0.176336f, -0.300000f,
	-0.242705f, 0.176336f, -0.300000f, -0.285317f, 0.0927050f, -0.300000f,
	-0.285317f, 0.0927050f, -0.300000f, -0.176336f, 0.242705f, 0.000000f,
	-0.176336f, 0.242705f, -0.300000f, -0.176336f, 0.242705f, -0.300000f,
	-0.0927050f, 0.285317f, 0.000000f, -0.0927050f, 0.285317f, -0.300000f,
	-0.0927050f, 0.285317f, -0.300000f, 0.000000f, 0.300000f, 0.000000f,
	0.000000f, 0.300000f, -0.300000f, 0.000000f, 0.300000f, -0.300000f,
	0.0927050f, 0.285317f, 0.000000f, 0.0927050f, 0.285317f, -0.300000f,
	0.0927050f, 0.285317f, -0.300000f, 0.176336f, 0.242705f, 0.000000f,
	0.176336f, 0.242705f, -0.300000f, 0.176336f, 0.242705f, -0.300000f,
	0.242705f, 0.176336f, 0.000000f, 0.242705f, 0.176336f, -0.300000f,
	0.242705f, 0.176336f, -0.300000f, 0.285317f, 0.0927050f, 0.000000f,
	0.285317f, 0.0927050f, -0.300000f, 0.285317f, 0.0927050f, -0.300000f,
	0.300000f, 0.000000f, 0.000000f, 0.300000f, 0.000000f, -0.300000f,
	0.300000f, 0.000000f, -0.300000f, 0.285317f, -0.0927050f, 0.000000f,
	0.285317f, -0.0927050f, -0.300000f, 0.285317f, -0.0927050f, -0.300000f,
	0.242705f, -0.176336f, 0.000000f, 0.242705f, -0.176336f, -0.300000f,
	0.242705f, -0.176336f, -0.300000f, 0.176336f, -0.242705f, 0.000000f,
	0.176336f, -0.242705f, -0.300000f, 0.176336f, -0.242705f, -0.300000f,
	0.0927050f, -0.285317f, 0.000000f, 0.0927050f, -0.285317f, -0.300000f,
	0.0927050f, -0.285317f, -0.300000f, 0.000000f, -0.300000f, 0.000000f,
	0.000000f, -0.300000f, -0.300000f, 0.000000f, -0.300000f, -0.300000f,
	-0.0927050f, -0.285317f, 0.000000f, -0.0927050f, -0.285317f, -0.300000f,
	-0.0927050f, -0.285317f, -0.300000f, -0.176336f, -0.242705f, 0.000000f,
	-0.176336f, -0.242705f, -0.300000f, -0.176336f, -0.242705f, -0.300000f,
	-0.242705f, -0.176336f, 0.000000f, -0.242705f, -0.176336f, -0.300000f,
	-0.242705f, -0.176336f, -0.300000f, -0.285317f, -0.0927050f, 0.000000f,
	-0.285317f, -0.0927050f, -0.300000f, -0.285317f, -0.0927050f, -0.300000f,
	-0.300000f, 0.000000f, 0.000000f, -0.300000f, 0.000000f, -0.300000f,
	-0.300000f, 0.000000f, -0.300000f, -0.194164f, 0.141069f, -0.300000f,
	-0.194164f, 0.141069f, -0.300000f, -0.228254f, 0.0741640f, -0.300000f,
	-0.228254f, 0.0741640f, -0.300000f, -0.141069f, 0.194164f, -0.300000f,
	-0.141069f, 0.194164f, -0.300000f, -0.0741640f, 0.228254f, -0.300000f,
	-0.0741640f, 0.228254f, -0.300000f, 0.000000f, 0.240000f, -0.300000f,
	0.000000f, 0.240000f, -0.300000f, 0.0741640f, 0.228254f, -0.300000f,
	0.0741640f, 0.228254f, -0.300000f, 0.141069f, 0.194164f, -0.300000f,
	0.141069f, 0.194164f, -0.300000f, 0.194164f, 0.141069f, -0.300000f,
	0.194164f, 0.141069f, -0.300000f, 0.228254f, 0.0741640f, -0.300000f,
	0.228254f, 0.0741640f, -0.300000f, 0.240000f, 0.000000f, -0.300000f,
	0.240000f, 0.000000f, -0.300000f, 0.228254f, -0.0741640f, -0.300000f,
	0.228254f, -0.0741640f, -0.300000f, 0.194164f, -0.141069f, -0.300000f,
	0.194164f, -0.141069f, -0.300000f, 0.141069f, -0.194164f, -0.300000f,
	0.141069f, -0.194164f, -0.300000f, 0.0741640f, -0.228254f, -0.300000f,
	0.0741640f, -0.228254f, -0.300000f, 0.000000f, -0.240000f, -0.300000f,
	0.000000f, -0.240000f, -0.300000f, -0.0741640f, -0.228254f, -0.300000f,
	-0.0741640f, -0.228254f, -0.300000f, -0.141068f, -0.194164f, -0.300000f,
	-0.141068f, -0.194164f, -0.300000f, -0.194164f, -0.141068f, -0.300000f,
	-0.194164f, -0.141068f, -0.300000f, -0.228254f, -0.0741640f, -0.300000f,
	-0.228254f, -0.0741640f, -0.300000f, -0.240000f, 0.000000f, -0.300000f,
	-0.240000f, 0.000000f, -0.300000f, -0.228254f, 0.0741640f, 0.000000f,
	-0.194164f, 0.141069f, 0.000000f, -0.141069f, 0.194164f, 0.000000f,
	-0.0741640f, 0.228254f, 0.000000f, 0.000000f, 0.240000f, 0.000000f,
	0.0741640f, 0.228254f, 0.000000f, 0.141069f, 0.194164f, 0.000000f,
	0.194164f, 0.141069f, 0.000000f, 0.228254f, 0.0741640f, 0.000000f,
	0.240000f, 0.000000f, 0.000000f, 0.228254f, -0.0741640f, 0.000000f,
	0.194164f, -0.141069f, 0.000000f, 0.141069f, -0.194164f, 0.000000f,
	0.0741640f, -0.228254f, 0.000000f, 0.000000f, -0.240000f, 0.000000f,
	-0.0741640f, -0.228254f, 0.000000f, -0.141068f, -0.194164f, 0.000000f,
	-0.194164f, -0.141068f, 0.000000f, -0.228254f, -0.0741640f, 0.000000f,
	-0.240000f, 0.000000f, 0.000000f, 0.306365f, 0.350000f, 0.164697f,
	0.313467f, 0.350000f, 0.178636f, 0.313467f, 0.370000f, 0.178636f,
	0.313467f, 0.370000f, 0.178636f, 0.306365f, 0.370000f, 0.164697f,
	0.306365f, 0.370000f, 0.164697f, 0.324529f, 0.350000f, 0.189697f,
	0.324529f, 0.370000f, 0.189697f, 0.324529f, 0.370000f, 0.189697f,
	0.338467f, 0.350000f, 0.196799f, 0.338467f, 0.370000f, 0.196799f,
	0.338467f, 0.370000f, 0.196799f, 0.353918f, 0.350000f, 0.199246f,
	0.353918f, 0.370000f, 0.199246f, 0.353918f, 0.370000f, 0.199246f,
	0.369369f, 0.350000f, 0.196799f, 0.369369f, 0.370000f, 0.196799f,
	0.369369f, 0.370000f, 0.196799f, 0.383307f, 0.350000f, 0.189697f,
	0.383307f, 0.370000f, 0.189697f, 0.383307f, 0.370000f, 0.189697f,
	0.394369f, 0.350000f, 0.178636f, 0.394369f, 0.370000f, 0.178636f,
	0.394369f, 0.370000f, 0.178636f, 0.401471f, 0.350000f, 0.164697f,
	0.401471f, 0.370000f, 0.164697f, 0.401471f, 0.370000f, 0.164697f,
	0.403918f, 0.350000f, 0.149246f, 0.403918f, 0.370000f, 0.149246f,
	0.403918f, 0.370000f, 0.149246f, 0.401471f, 0.350000f, 0.133795f,
	0.401471f, 0.370000f, 0.133795f, 0.401471f, 0.370000f, 0.133795f,
	0.394369f, 0.350000f, 0.119857f, 0.394369f, 0.370000f, 0.119857f,
	0.394369f, 0.370000f, 0.119857f, 0.383307f, 0.350000f, 0.108795f,
	0.383307f, 0.370000f, 0.108795f, 0.383307f, 0.370000f, 0.108795f,
	0.369369f, 0.350000f, 0.101693f, 0.369369f, 0.370000f, 0.101693f,
	0.369369f, 0.370000f, 0.101693f, 0.353918f, 0.350000f, 0.0992460f,
	0.353918f, 0.370000f, 0.0992460f, 0.353918f, 0.370000f, 0.0992460f,
	0.338467f, 0.350000f, 0.101693f, 0.338467f, 0.370000f, 0.101693f,
	0.338467f, 0.370000f, 0.101693f, 0.324529f, 0.350000f, 0.108795f,
	0.324529f, 0.370000f, 0.108795f, 0.324529f, 0.370000f, 0.108795f,
	0.313467f, 0.350000f, 0.119857f, 0.313467f, 0.370000f, 0.119857f,
	0.313467f, 0.370000f, 0.119857f, 0.306365f, 0.350000f, 0.133795f,
	0.306365f, 0.370000f, 0.133795f, 0.306365f, 0.370000f, 0.133795f,
	0.303918f, 0.350000f, 0.149246f, 0.303918f, 0.370000f, 0.149246f,
	0.303918f, 0.370000f, 0.149246f, 0.353918f, 0.370000f, 0.149246f
};
static GLfloat cameraNormals[] = {
	1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, -1.00000f, 0.000000f, 0.000000f,
	0.000000f, 1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	1.00000f, 0.000000f, 0.000000f, 0.000000f, 1.00000f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, -1.00000f, 0.000000f, 0.000000f,
	0.000000f, 0.000000f, 1.00000f, 0.000000f, 1.00000f, 0.000000f,
	1.00000f, 0.000000f, 0.000000f, 0.000000f, 0.000000f, 1.00000f,
	0.000000f, 1.00000f, 0.000000f, -1.00000f, 0.000000f, 0.000000f,
	0.000000f, -1.00000f, 0.000000f, 0.000000f, 0.000000f, 1.00000f,
	1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f, 0.000000f,
	0.000000f, 0.000000f, 1.00000f, -0.951057f, 0.309016f, 0.000000f,
	-0.809017f, 0.587785f, 0.000000f, -0.809017f, 0.587785f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, -0.951057f, 0.309016f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, -0.587785f, 0.809017f, 0.000000f,
	-0.587785f, 0.809017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.309017f, 0.951057f, 0.000000f, -0.309017f, 0.951057f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, 0.000000f, 1.00000f, 0.000000f,
	0.000000f, 1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.309017f, 0.951056f, 0.000000f, 0.309017f, 0.951056f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, 0.587785f, 0.809017f, 0.000000f,
	0.587785f, 0.809017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.809017f, 0.587785f, 0.000000f, 0.809017f, 0.587785f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, 0.951057f, 0.309017f, 0.000000f,
	0.951057f, 0.309017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	1.00000f, 0.000000f, 0.000000f, 1.00000f, 0.000000f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, 0.951057f, -0.309017f, 0.000000f,
	0.951057f, -0.309017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.809017f, -0.587785f, 0.000000f, 0.809017f, -0.587785f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, 0.587785f, -0.809017f, 0.000000f,
	0.587785f, -0.809017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.309017f, -0.951057f, 0.000000f, 0.309017f, -0.951057f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, 0.000000f, -1.00000f, 0.000000f,
	0.000000f, -1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.309017f, -0.951056f, 0.000000f, -0.309017f, -0.951056f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, -0.587785f, -0.809017f, 0.000000f,
	-0.587785f, -0.809017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.809017f, -0.587785f, 0.000000f, -0.809017f, -0.587785f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, -0.951057f, -0.309017f, 0.000000f,
	-0.951057f, -0.309017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-1.00000f, -1.00000e-006f, 0.000000f, -1.00000f, -1.00000e-006f, 0.000000f,
	0.000000f, 0.000000f, -1.00000f, 0.000000f, 0.000000f, -1.00000f,
	0.809017f, -0.587785f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.951057f, -0.309016f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.587785f, -0.809017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.309017f, -0.951056f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.000000f, -1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.309017f, -0.951056f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.587785f, -0.809017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.809017f, -0.587785f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.951057f, -0.309017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-1.00000f, 0.000000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.951057f, 0.309017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.809017f, 0.587785f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.587785f, 0.809017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	-0.309017f, 0.951057f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.000000f, 1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.309017f, 0.951056f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.587785f, 0.809017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.809017f, 0.587785f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.951057f, 0.309017f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	1.00000f, 1.00000e-006f, 0.000000f, 0.951057f, -0.309016f, 0.000000f,
	0.809017f, -0.587785f, 0.000000f, 0.587785f, -0.809017f, 0.000000f,
	0.309017f, -0.951056f, 0.000000f, 0.000000f, -1.00000f, 0.000000f,
	-0.309017f, -0.951056f, 0.000000f, -0.587785f, -0.809017f, 0.000000f,
	-0.809017f, -0.587785f, 0.000000f, -0.951057f, -0.309017f, 0.000000f,
	-1.00000f, 0.000000f, 0.000000f, -0.951057f, 0.309017f, 0.000000f,
	-0.809017f, 0.587785f, 0.000000f, -0.587785f, 0.809017f, 0.000000f,
	-0.309017f, 0.951057f, 0.000000f, 0.000000f, 1.00000f, 0.000000f,
	0.309017f, 0.951056f, 0.000000f, 0.587785f, 0.809017f, 0.000000f,
	0.809017f, 0.587785f, 0.000000f, 0.951057f, 0.309017f, 0.000000f,
	1.00000f, 1.00000e-006f, 0.000000f, -0.951057f, 0.000000f, 0.309017f,
	-0.809017f, 0.000000f, 0.587786f, -0.809017f, 0.000000f, 0.587786f,
	0.000000f, 1.00000f, -1.00000e-006f, -0.951057f, 0.000000f, 0.309017f,
	0.000000f, 1.00000f, -2.00000e-006f, -0.587785f, 0.000000f, 0.809017f,
	-0.587785f, 0.000000f, 0.809017f, 0.000000f, 1.00000f, 0.000000f,
	-0.309016f, 0.000000f, 0.951057f, -0.309016f, 0.000000f, 0.951057f,
	0.000000f, 1.00000f, 0.000000f, 1.00000e-006f, 0.000000f, 1.00000f,
	1.00000e-006f, 0.000000f, 1.00000f, 0.000000f, 1.00000f, 0.000000f,
	0.309018f, 0.000000f, 0.951056f, 0.309018f, 0.000000f, 0.951056f,
	0.000000f, 1.00000f, 0.000000f, 0.587785f, 0.000000f, 0.809017f,
	0.587785f, 0.000000f, 0.809017f, 0.000000f, 1.00000f, 0.000000f,
	0.809017f, 0.000000f, 0.587786f, 0.809017f, 0.000000f, 0.587786f,
	0.000000f, 1.00000f, 0.000000f, 0.951057f, 0.000000f, 0.309017f,
	0.951057f, 0.000000f, 0.309017f, 0.000000f, 1.00000f, 1.00000e-006f,
	1.00000f, 0.000000f, 0.000000f, 1.00000f, 0.000000f, 0.000000f,
	0.000000f, 1.00000f, 2.00000e-006f, 0.951057f, 0.000000f, -0.309017f,
	0.951057f, 0.000000f, -0.309017f, 0.000000f, 1.00000f, 2.00000e-006f,
	0.809017f, 0.000000f, -0.587786f, 0.809017f, 0.000000f, -0.587786f,
	0.000000f, 1.00000f, 1.00000e-006f, 0.587785f, 0.000000f, -0.809017f,
	0.587785f, 0.000000f, -0.809017f, 0.000000f, 1.00000f, 0.000000f,
	0.309017f, 0.000000f, -0.951056f, 0.309017f, 0.000000f, -0.951056f,
	0.000000f, 1.00000f, 0.000000f, 0.000000f, 0.000000f, -1.00000f,
	0.000000f, 0.000000f, -1.00000f, 0.000000f, 1.00000f, 0.000000f,
	-0.309017f, 0.000000f, -0.951056f, -0.309017f, 0.000000f, -0.951056f,
	0.000000f, 1.00000f, 0.000000f, -0.587786f, 0.000000f, -0.809017f,
	-0.587786f, 0.000000f, -0.809017f, 0.000000f, 1.00000f, 0.000000f,
	-0.809017f, 0.000000f, -0.587785f, -0.809017f, 0.000000f, -0.587785f,
	0.000000f, 1.00000f, 0.000000f, -0.951056f, 0.000000f, -0.309018f,
	-0.951056f, 0.000000f, -0.309018f, 0.000000f, 1.00000f, -1.00000e-006f,
	-1.00000f, 0.000000f, -1.00000e-006f, -1.00000f, 0.000000f, -1.00000e-006f,
	0.000000f, 1.00000f, -2.00000e-006f, 0.000000f, 1.00000f, 0.000000f
};
static GLint cameraIndices[] = {
	2, 5, 11, 5, 8, 10, 7, 17, 7, 14, 16, 13, 23, 13, 20, 22,
	19, 1, 19, 4, 3, 18, 6, 18, 12, 21, 0, 15, 0, 9, 203, 149,
	204, 147, 204, 152, 204, 155, 204, 158, 204, 161, 204, 164, 204, 167, 204, 170,
	204, 173, 204, 176, 204, 179, 204, 182, 204, 185, 204, 188, 204, 191, 204, 194,
	204, 197, 204, 200, 203, 144, 148, 144, 202, 201, 199, 198, 196, 195, 193, 192,
	190, 189, 187, 186, 184, 183, 181, 180, 178, 177, 175, 174, 172, 171, 169, 168,
	166, 165, 163, 162, 160, 159, 157, 156, 154, 153, 151, 150, 146, 145, 148, 145,
	144, 123, 87, 124, 87, 125, 85, 126, 89, 127, 91, 128, 93, 129, 95, 130,
	97, 131, 99, 132, 101, 133, 103, 134, 105, 135, 107, 136, 109, 137, 111, 138,
	113, 139, 115, 140, 117, 141, 119, 142, 121, 143, 123, 143, 124, 29, 86, 29,
	122, 83, 120, 80, 118, 77, 116, 74, 114, 71, 112, 68, 110, 65, 108, 62,
	106, 59, 104, 56, 102, 53, 100, 50, 98, 47, 96, 44, 94, 41, 92, 38,
	90, 35, 88, 32, 84, 27, 86, 27, 29, 24, 28, 24, 82, 81, 79, 78,
	76, 75, 73, 72, 70, 69, 67, 66, 64, 63, 61, 60, 58, 57, 55, 54,
	52, 51, 49, 48, 46, 45, 43, 42, 40, 39, 37, 36, 34, 33, 31, 30,
	26, 25, 28, 25, 24
};

CameraBase::CameraBase() {
    memset(m_modelMatrix, 0, 16 * sizeof(float));
    m_modelMatrix[0] = 1.f;
    m_modelMatrix[5] = 1.f;
    m_modelMatrix[10] = 1.f;
    m_modelMatrix[15] = 1.f;
    memset(m_viewMatrix, 0, 16 * sizeof(float));
    m_viewMatrix[0] = 1.f;
    m_viewMatrix[5] = 1.f;
    m_viewMatrix[10] = 1.f;
    m_viewMatrix[15] = 1.f;
    memset(m_projectMatrix, 0, 16 * sizeof(float));
    m_projectMatrix[0] = 1.f;
    m_projectMatrix[5] = 1.f;
    m_projectMatrix[10] = 1.f;
    m_projectMatrix[15] = 1.f;


    std::string vsCode =
        "#version 330 core                                             \n"
        "layout (location = 0) in vec3 aPos;                           \n"
        "uniform mat4 view;                                            \n"
        "uniform mat4 model;                                           \n"
        "uniform mat4 project;                                         \n"
        "void main(){                                                  \n"
        "    gl_Position = project * view * model * vec4(aPos, 1.f);   \n"
        "}";

    std::string fsCode =
        "#version 330 core                                             \n"
        "out vec4 FragColor;                                           \n"
        "void main(){                                                  \n"
        "    FragColor = vec4(1.f, 0.f, 0.f, 1.f);                     \n"
        "}";

    m_pShader = new Shader(vsCode, fsCode);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cameraVertices), cameraVertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cameraIndices), cameraIndices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

CameraBase::~CameraBase() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    delete m_pShader;
    m_pShader = NULL;
}

void CameraBase::Draw() {
    glEnable(GL_DEPTH_TEST);

    m_pShader->Use();
    
    m_pShader->SetMat4("view", m_viewMatrix);
    m_pShader->SetMat4("model", m_modelMatrix);
    m_pShader->SetMat4("project", m_projectMatrix);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_INT, (const void*)(0 * sizeof(unsigned int)));
    glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_INT, (const void*)(5 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_INT, (const void*)(10 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_INT, (const void*)(15 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_INT, (const void*)(20 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_INT, (const void*)(25 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 39, GL_UNSIGNED_INT, (const void*)(30 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 44, GL_UNSIGNED_INT, (const void*)(69 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 44, GL_UNSIGNED_INT, (const void*)(113 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 44, GL_UNSIGNED_INT, (const void*)(157 * sizeof(unsigned int)));
	glDrawElements(GL_TRIANGLE_STRIP, 44, GL_UNSIGNED_INT, (const void*)(201 * sizeof(unsigned int)));
    
    m_pShader->UnUse();

    glDisable(GL_DEPTH_TEST);
}