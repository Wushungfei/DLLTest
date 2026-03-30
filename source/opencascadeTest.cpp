#if 0
#include <iostream>
#include <TDocStd_Document.hxx>
#include <STEPControl_Reader.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>

int main() {
    // 创建一个新的文档
    Handle(TDocStd_Document) doc = new TDocStd_Document();

    // 创建STEP文件读取器
    STEPControl_Reader reader;
    reader.SetColorMode(true); // 读取颜色信息

    // 读取STEP文件
    IFSelect_ReturnStatus status = reader.ReadFile("your_model_file.step");
    if (status != IFSelect_RetDone) {
        std::cerr << "Error: Unable to read STEP file." << std::endl;
        return 1;
    }

    // 将STEP文件内容传输到文档中
    status = reader.Transfer(doc->Main());
    if (status != IFSelect_RetDone) {
        std::cerr << "Error: Unable to transfer STEP file." << std::endl;
        return 1;
    }

    // 获取模型的拓扑结构
    TopoDS_Shape shape = doc->Main()->Shape();

    // 使用拓扑探索器遍历所有的面
    TopExp_Explorer explorer;
    explorer.Init(shape, TopAbs_FACE);
    while (explorer.More()) {
        // 获取当前面
        TopoDS_Face face = TopoDS::Face(explorer.Current());

        // 这里可以添加代码来处理每个面，例如获取面的一些属性

        std::cout << "Found a face." << std::endl;

        // 移动到下一个面
        explorer.Next();
    }

    std::cout << "Model read successfully." << std::endl;

    return 0;
}
#endif