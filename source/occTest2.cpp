#if 0
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <BRepTools.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <Draw.hxx>
#include <DrawDimetric.hxx>
#include <IVtkTools.hxx>
#include <STEPCAFControl_Reader.hxx>
#include <TDocStd_Document.hxx>
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <STEP file>" << std::endl;
        return 1;
    }

    // 初始化Draw框架
    Draw_Init(argv[0], Draw_Dimension_2D);
    Draw_Application theApp;

    // 创建并初始化V3d视图
    Handle(V3d_Viewer) aViewer = theApp.CreateViewer("Viewer");
    Handle(V3d_View) aView = aViewer->CreateView();
    aView->SetLightOn();

    // 创建交互式上下文和形状
    Handle(AIS_InteractiveContext) anAISContext = new AIS_InteractiveContext(aViewer);
    Handle(AIS_Shape) aShape = new AIS_Shape();

    // 读取STEP文件
    STEPCAFControl_Reader aReader;
    IFSelect_ReturnStatus status = aReader.ReadFile(argv[1]);
    if (status != IFSelect_RetDone) {
        std::cerr << "Failed to read STEP file" << std::endl;
        return 1;
    }

    // 将读取的模型转换为TopoDS_Shape
    TopoDS_Shape aShapeData = aReader.Shape();
    if (aShapeData.IsNull()) {
        std::cerr << "Failed to get shape from STEP file" << std::endl;
        return 1;
    }

    // 将形状添加到交互式上下文中
    aShape->SetShape(aShapeData);
    anAISContext->Display(aShape, Standard_True);

    // 显示视图
    aViewer->Redraw();

    // 启动事件循环
    theApp.MainLoop();

    return 0;
}
#endif