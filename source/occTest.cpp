#if 0
#include <TopoDS.hxx>
#include <STEPControl_Reader.hxx>
#include <TopExp_Explorer.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <BRep_Tool.hxx>

#include <GCPnts_UniformAbscissa.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt.hxx>
#include <BRepTools.hxx>
#include <BRepClass_FaceClassifier.hxx>

// 采样曲面并返回采样点数组的函数
TColgp_Array1OfPnt SampleSurface(const TopoDS_Face& theFace, const Standard_Integer theNbPointsU, const Standard_Integer theNbPointsV) {
    // 获取曲面的几何表面
    Handle(Geom_Surface) theSurface = BRep_Tool::Surface(theFace);

    // 创建一个点的数组来存储采样点
    TColgp_Array1OfPnt thePoints = TColgp_Array1OfPnt(1, theNbPointsU * theNbPointsV);

    // 获取曲面的参数范围
    Standard_Real theUFirst, theULast, theVFirst, theVLast;
    BRepTools::UVBounds(theFace, theUFirst, theULast, theVFirst, theVLast);

    // 计算采样点
    Standard_Integer index = 1;
    for (Standard_Integer i = 0; i < theNbPointsV; ++i) {
        for (Standard_Integer j = 0; j < theNbPointsU; ++j) {
            Standard_Real theUParam = theUFirst + (theULast - theUFirst) * j / (theNbPointsU - 1);
            Standard_Real theVParam = theVFirst + (theVLast - theVFirst) * i / (theNbPointsV - 1);
            gp_Pnt thePnt;
            thePnt = theSurface->Value(theUParam, theVParam);
            thePoints.SetValue(index, thePnt);
            index++;
        }
    }
    return thePoints;
}

int main()
{
    std::cout << "-----ReadingSTEP START-----" << std::endl;
    //读取STEP文件
    STEPControl_Reader aReader_Step;
    auto err  = aReader_Step.ReadFile("D:/GitProject/libTest/TestFile/screw.step");
    //检查文件加载状态
    aReader_Step.PrintCheckLoad(Standard_False, IFSelect_ItemsByEntity);
    if (err == IFSelect_RetDone)
    {
        //加载step文件
        Standard_Integer NbRoots = aReader_Step.NbRootsForTransfer();// 获取可转移根的数量
        Standard_Integer num = aReader_Step.TransferRoots();//翻译所有可转换的根，并返回//成功翻译的次数
        //读取到TopoDS_Shape结构中
        TopoDS_Shape aShape = aReader_Step.Shape();
        // 遍历所有的子形状
        TopExp_Explorer anExplorer(aShape, TopAbs_FACE);
        while (anExplorer.More())
        {
            // 获取当前的形状
            TopoDS_Face aFace = TopoDS::Face(anExplorer.Current()) ;
            // 获取面ID号
           /* size_t faceID = std::hash<TopoDS_Face>()(aFace);
            std::cout << faceID << std::endl;*/
            // 这里可以添加代码来获取面类型，例如：
            // 检查面是否是平面
           /* GeomLib_IsPlanarSurface aPlanarChecker(BRep_Tool::Surface(aFace));
            if (aPlanarChecker.IsPlanar())
            {
                std::cout << "Face Type: Planar" << std::endl;
            }
            else
            {
                std::cout << "Face Type: Non-Planar" << std::endl;
            }*/
            BRepAdaptor_Surface surface(aFace);

            // 判断曲面类型
            GeomAbs_SurfaceType surfaceType = surface.GetType();
            switch (surfaceType)
            {
            case GeomAbs_Plane:
                std::cout << "Face Type: Planar" << std::endl;
                break;
            case GeomAbs_Cylinder:
                std::cout << "Face Type: Cylindrical" << std::endl;
                break;
            case GeomAbs_Cone:
                std::cout << "Face Type: Conical" << std::endl;
                break;
            case GeomAbs_Sphere:
                std::cout << "Face Type: Spherical" << std::endl;
                break;
            default:
                std::cout << "Face Type: Other" << std::endl;
                break;
            }
            auto points = SampleSurface(aFace,10, 10);
            anExplorer.Next();
        }
    }
    return 0;
}
#endif