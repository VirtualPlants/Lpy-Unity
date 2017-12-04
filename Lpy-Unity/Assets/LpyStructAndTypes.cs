using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace Lpy
{
    public class LpyStructAndType
    {
        public struct LpyVector3
        {
            public float x;
            public float y;
            public float z;
        }

        public unsafe struct LpyMatrix4
        {
            public fixed float column1[4];
            public fixed float column2[4];
            public fixed float column3[4];
            public fixed float column4[4];
        }

        public struct LpyTriangle
        {
            public LpyVector3 point1;
            public LpyVector3 point2;
            public LpyVector3 point3;
        }

        public struct LpyGeometryInfo
        {
            public LpyTriangle[] triangles;
        }

        public struct LpyGeometryInfoPtr
        {
            public int triangleSize;
            public IntPtr triangles;
        }

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakeCylinderCallback(LpyVector3 pos, LpyMatrix4 rotMatrix, float raduis, float length, int resolution, int color);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakeConeCallback(LpyVector3 pos, LpyMatrix4 rotMatrix, float reduis, float topraduis, float length, int resolution, int color);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakeSphereCallback(LpyVector3 pos, float raduis, int resolution, int color);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakeBoxCallback(LpyVector3 pos, LpyMatrix4 rotMatrix, float length, float botradius, float topradius, int color);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakeCircleCallback(LpyVector3 pos, LpyMatrix4 rotMatrix, float radius, int resolution, int color);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakeQuadCallback(LpyVector3 pos, LpyMatrix4 rotMatrix, float length, float botradius, float topradius, int color);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakeSurfaceCallback(LpyVector3 pos, LpyMatrix4 rotMatrix, string name, float scale, int color);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakePolygonCallback(LpyVector3 pos, LpyMatrix4 rotMatrix, IntPtr points, int size, bool concavetest, int color);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void MakeGeneralizedGeometryCallback(LpyVector3 pos, LpyMatrix4 rotMatrix, LpyGeometryInfoPtr info);
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void WriteCallback(string str);

#if UNITY_EDITOR
        public delegate void SetMakeCylinder(MakeCylinderCallback callback);
        public delegate void SetMakeCone(MakeConeCallback callback);
        public delegate void SetMakeSphere(MakeSphereCallback callback);
        public delegate void SetMakeBox(MakeBoxCallback callback);
        public delegate void SetMakeCircle(MakeCircleCallback callback);
        public delegate void SetMakeQuad(MakeQuadCallback callback);
        public delegate void SetMakeSurface(MakeSurfaceCallback callback);
        public delegate void SetMakePolygon(MakePolygonCallback callback);
        public delegate void SetMakeGeneralizedGeometry(MakeGeneralizedGeometryCallback callback);

        public delegate void SetColorListSize(int size);

        public delegate void Interpret_LString(string lstring);

        public delegate void SetDebug(WriteCallback callback);
        public delegate void SetWarning(WriteCallback callback);
        public delegate void SetError(WriteCallback callback);
#else
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakeCylinder(MakeCylinderCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakeCone(MakeConeCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakeSphere(MakeSphereCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakeBox(MakeBoxCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakeCircle(MakeCircleCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakeQuad(MakeQuadCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakeSurface(MakeSurfaceCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakePolygon(MakePolygonCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetMakeGeneralizedGeometry(MakeGeneralizedGeometryCallback callback);

        [DllImport("Lpy_Windows.dll")]
        public static extern void SetColorListSize(int size);

        [DllImport("Lpy_Windows.dll")]
        public static extern void Interpret_LString(string lstring);

        [DllImport("Lpy_Windows.dll")]
        public static extern void SetDebug(WriteCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetWarning(WriteCallback callback);
        [DllImport("Lpy_Windows.dll")]
        public static extern void SetError(WriteCallback callback);
#endif
    }
}
