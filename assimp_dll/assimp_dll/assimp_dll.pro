#-------------------------------------------------
#
# Project created by QtCreator 2017-08-17T08:45:05
#
#-------------------------------------------------

QT       -= core gui\

CONFIG += c++11


TARGET = assimp_dll
TEMPLATE = lib

DEFINES += ASSIMP_DLL_LIBRARY

SOURCES += \
    3DSConverter.cpp \
    3DSExporter.cpp \
    3DSLoader.cpp \
    ACLoader.cpp \
    ASELoader.cpp \
    ASEParser.cpp \
    AssbinExporter.cpp \
    AssbinLoader.cpp \
    Assimp.cpp \
    AssimpCExport.cpp \
    AssxmlExporter.cpp \
    B3DImporter.cpp \
    BaseImporter.cpp \
    BaseProcess.cpp \
    Bitmap.cpp \
    BlenderBMesh.cpp \
    BlenderDNA.cpp \
    BlenderDNA.inl \
    BlenderLoader.cpp \
    BlenderModifier.cpp \
    BlenderScene.cpp \
    BlenderTessellator.cpp \
    BVHLoader.cpp \
    C4DImporter.cpp \
    CalcTangentsProcess.cpp \
    COBLoader.cpp \
    ColladaExporter.cpp \
    ColladaLoader.cpp \
    ColladaParser.cpp \
    ComputeUVMappingProcess.cpp \
    ConvertToLHProcess.cpp \
    CSMLoader.cpp \
    D3MFImporter.cpp \
    D3MFOpcPackage.cpp \
    DeboneProcess.cpp \
    DefaultIOStream.cpp \
    DefaultIOSystem.cpp \
    DefaultLogger.cpp \
    DXFLoader.cpp \
    Exporter.cpp \
    FBXAnimation.cpp \
    FBXBinaryTokenizer.cpp \
    FBXConverter.cpp \
    FBXDeformer.cpp \
    FBXDocument.cpp \
    FBXDocumentUtil.cpp \
    FBXImporter.cpp \
    FBXMaterial.cpp \
    FBXMeshGeometry.cpp \
    FBXModel.cpp \
    FBXNodeAttribute.cpp \
    FBXParser.cpp \
    FBXProperties.cpp \
    FBXTokenizer.cpp \
    FBXUtil.cpp \
    FindDegenerates.cpp \
    FindInstancesProcess.cpp \
    FindInvalidDataProcess.cpp \
    FixNormalsStep.cpp \
    GenFaceNormalsProcess.cpp \
    GenVertexNormalsProcess.cpp \
    glTFAsset.inl \
    glTFAssetWriter.inl \
    glTFExporter.cpp \
    glTFImporter.cpp \
    HMPLoader.cpp \
    IFCBoolean.cpp \
    IFCCurve.cpp \
    IFCGeometry.cpp \
    IFCLoader.cpp \
    IFCMaterial.cpp \
    IFCOpenings.cpp \
    IFCProfile.cpp \
    IFCReaderGen.cpp \
    IFCUtil.cpp \
    Importer.cpp \
    ImporterRegistry.cpp \
    ImproveCacheLocality.cpp \
    IRRLoader.cpp \
    IRRMeshLoader.cpp \
    IRRShared.cpp \
    JoinVerticesProcess.cpp \
    LimitBoneWeightsProcess.cpp \
    LWOAnimation.cpp \
    LWOBLoader.cpp \
    LWOLoader.cpp \
    LWOMaterial.cpp \
    LWSLoader.cpp \
    MakeVerboseFormat.cpp \
    MaterialSystem.cpp \
    MD2Loader.cpp \
    MD3Loader.cpp \
    MD5Loader.cpp \
    MD5Parser.cpp \
    MDCLoader.cpp \
    MDLLoader.cpp \
    MDLMaterialLoader.cpp \
    MS3DLoader.cpp \
    NDOLoader.cpp \
    NFFLoader.cpp \
    ObjExporter.cpp \
    ObjFileImporter.cpp \
    ObjFileMtlImporter.cpp \
    ObjFileParser.cpp \
    OFFLoader.cpp \
    OgreBinarySerializer.cpp \
    OgreImporter.cpp \
    OgreMaterial.cpp \
    OgreStructs.cpp \
    OgreXmlSerializer.cpp \
    OpenGEXExporter.cpp \
    OpenGEXImporter.cpp \
    OptimizeGraph.cpp \
    OptimizeMeshes.cpp \
    PlyExporter.cpp \
    PlyLoader.cpp \
    PlyParser.cpp \
    PostStepRegistry.cpp \
    PretransformVertices.cpp \
    ProcessHelper.cpp \
    Q3BSPFileImporter.cpp \
    Q3BSPFileParser.cpp \
    Q3BSPZipArchive.cpp \
    Q3DLoader.cpp \
    RawLoader.cpp \
    RemoveComments.cpp \
    RemoveRedundantMaterials.cpp \
    RemoveVCProcess.cpp \
    SceneCombiner.cpp \
    ScenePreprocessor.cpp \
    SGSpatialSort.cpp \
    SIBImporter.cpp \
    SkeletonMeshBuilder.cpp \
    SMDLoader.cpp \
    SmoothingGroups.inl \
    SortByPTypeProcess.cpp \
    SpatialSort.cpp \
    SplitByBoneCountProcess.cpp \
    SplitLargeMeshes.cpp \
    StandardShapes.cpp \
    StepExporter.cpp \
    STEPFileEncoding.cpp \
    STEPFileReader.cpp \
    STLExporter.cpp \
    STLLoader.cpp \
    Subdivision.cpp \
    TargetAnimation.cpp \
    TerragenLoader.cpp \
    TextureTransform.cpp \
    TriangulateProcess.cpp \
    UnrealLoader.cpp \
    ValidateDataStructure.cpp \
    Version.cpp \
    VertexTriangleAdjacency.cpp \
    XFileExporter.cpp \
    XFileImporter.cpp \
    XFileParser.cpp \
    XGLLoader.cpp \
#    ../include/contrib/zlib/adler32.c \
#    ../include/contrib/zlib/compress.c \
#    ../include/contrib/zlib/crc32.c \
#    ../include/contrib/zlib/deflate.c \
#    ../include/contrib/zlib/gzclose.c \
#    ../include/contrib/zlib/gzlib.c \
#    ../include/contrib/zlib/gzread.c \
#    ../include/contrib/zlib/gzwrite.c \
#    ../include/contrib/zlib/infback.c \
#    ../include/contrib/zlib/inffast.c \
#    ../include/contrib/zlib/inflate.c \
#    ../include/contrib/zlib/inftrees.c \
#    ../include/contrib/zlib/trees.c \
#    ../include/contrib/zlib/uncompr.c \
#    ../include/contrib/zlib/zutil.c \
    ../include/contrib/ConvertUTF/ConvertUTF.c \
    ../include/contrib/poly2tri/poly2tri/sweep/advancing_front.cc \
    ../include/contrib/poly2tri/poly2tri/sweep/cdt.cc \
    ../include/contrib/poly2tri/poly2tri/sweep/sweep.cc \
    ../include/contrib/poly2tri/poly2tri/sweep/sweep_context.cc \
    ../include/contrib/poly2tri/poly2tri/common/shapes.cc \
    ../include/contrib/irrXML/irrXML.cpp \
    ../include/contrib/unzip/ioapi.c \
    ../include/contrib/unzip/unzip.c \
    ../include/contrib/clipper/clipper.cpp \
    ../include/contrib/openddlparser/code/DDLNode.cpp \
    ../include/contrib/openddlparser/code/OpenDDLCommon.cpp \
    ../include/contrib/openddlparser/code/OpenDDLExport.cpp \
    ../include/contrib/openddlparser/code/OpenDDLParser.cpp \
    ../include/contrib/openddlparser/code/Value.cpp

HEADERS += \
    3DSExporter.h \
    3DSHelper.h \
    3DSLoader.h \
    ACLoader.h \
    ASELoader.h \
    ASEParser.h \
    assbin_chunks.h \
    AssbinExporter.h \
    AssbinLoader.h \
    AssxmlExporter.h \
    B3DImporter.h \
    BaseImporter.h \
    BaseProcess.h \
    Bitmap.h \
    BlenderBMesh.h \
    BlenderDNA.h \
    BlenderIntermediate.h \
    BlenderLoader.h \
    BlenderModifier.h \
    BlenderScene.h \
    BlenderSceneGen.h \
    BlenderTessellator.h \
    BlobIOSystem.h \
    BVHLoader.h \
    ByteSwapper.h \
    C4DImporter.h \
    CalcTangentsProcess.h \
    CInterfaceIOWrapper.h \
    COBLoader.h \
    COBScene.h \
    ColladaExporter.h \
    ColladaHelper.h \
    ColladaLoader.h \
    ColladaParser.h \
    ComputeUVMappingProcess.h \
    ConvertToLHProcess.h \
    CSMLoader.h \
    D3MFImporter.h \
    D3MFOpcPackage.h \
    DeboneProcess.h \
    DefaultIOStream.h \
    DefaultIOSystem.h \
    DefaultProgressHandler.h \
    Defines.h \
    DXFHelper.h \
    DXFLoader.h \
    Exceptional.h \
    fast_atof.h \
    FBXCompileConfig.h \
    FBXConverter.h \
    FBXDocument.h \
    FBXDocumentUtil.h \
    FBXImporter.h \
    FBXImportSettings.h \
    FBXMeshGeometry.h \
    FBXParser.h \
    FBXProperties.h \
    FBXTokenizer.h \
    FBXUtil.h \
    FileLogStream.h \
    FileSystemFilter.h \
    FindDegenerates.h \
    FindInstancesProcess.h \
    FindInvalidDataProcess.h \
    FixNormalsStep.h \
    GenericProperty.h \
    GenFaceNormalsProcess.h \
    GenVertexNormalsProcess.h \
    glTFAsset.h \
    glTFAssetWriter.h \
    glTFExporter.h \
    glTFImporter.h \
    HalfLifeFileData.h \
    Hash.h \
    HMPFileData.h \
    HMPLoader.h \
    IFCLoader.h \
    IFCReaderGen.h \
    IFCUtil.h \
    IFF.h \
    Importer.h \
    ImproveCacheLocality.h \
    IRRLoader.h \
    IRRMeshLoader.h \
    IRRShared.h \
    irrXMLWrapper.h \
    JoinVerticesProcess.h \
    LimitBoneWeightsProcess.h \
    LineSplitter.h \
    LogAux.h \
    LWOAnimation.h \
    LWOFileData.h \
    LWOLoader.h \
    LWSLoader.h \
    Macros.h \
    MakeVerboseFormat.h \
    MaterialSystem.h \
    MathFunctions.h \
    MD2FileData.h \
    MD2Loader.h \
    MD2NormalTable.h \
    MD3FileData.h \
    MD3Loader.h \
    MD4FileData.h \
    MD5Loader.h \
    MD5Parser.h \
    MDCFileData.h \
    MDCLoader.h \
    MDCNormalTable.h \
    MDLDefaultColorMap.h \
    MDLFileData.h \
    MDLLoader.h \
    MemoryIOWrapper.h \
    MS3DLoader.h \
    NDOLoader.h \
    NFFLoader.h \
    ObjExporter.h \
    ObjFileData.h \
    ObjFileImporter.h \
    ObjFileMtlImporter.h \
    ObjFileParser.h \
    ObjTools.h \
    OFFLoader.h \
    OgreBinarySerializer.h \
    OgreImporter.h \
    OgreParsingUtils.h \
    OgreStructs.h \
    OgreXmlSerializer.h \
    OpenGEXExporter.h \
    OpenGEXImporter.h \
    OpenGEXStructs.h \
    OptimizeGraph.h \
    OptimizeMeshes.h \
    ParsingUtils.h \
    PlyExporter.h \
    PlyLoader.h \
    PlyParser.h \
    PolyTools.h \
    PretransformVertices.h \
    ProcessHelper.h \
    Profiler.h \
    Q3BSPFileData.h \
    Q3BSPFileImporter.h \
    Q3BSPFileParser.h \
    Q3BSPZipArchive.h \
    Q3DLoader.h \
    qnan.h \
    RawLoader.h \
    RemoveComments.h \
    RemoveRedundantMaterials.h \
    RemoveVCProcess.h \
    SceneCombiner.h \
    ScenePreprocessor.h \
    ScenePrivate.h \
    SGSpatialSort.h \
    SIBImporter.h \
    SkeletonMeshBuilder.h \
    SMDLoader.h \
    SmoothingGroups.h \
    SortByPTypeProcess.h \
    SpatialSort.h \
    SplitByBoneCountProcess.h \
    SplitLargeMeshes.h \
    StandardShapes.h \
    StdOStreamLogStream.h \
    StepExporter.h \
    STEPFile.h \
    STEPFileEncoding.h \
    STEPFileReader.h \
    STLExporter.h \
    STLLoader.h \
    StreamReader.h \
    StreamWriter.h \
    StringComparison.h \
    StringUtils.h \
    Subdivision.h \
    TargetAnimation.h \
    TerragenLoader.h \
    TextureTransform.h \
    TinyFormatter.h \
    TriangulateProcess.h \
    UnrealLoader.h \
    ValidateDataStructure.h \
    Vertex.h \
    VertexTriangleAdjacency.h \
    Win32DebugLogStream.h \
    XFileExporter.h \
    XFileHelper.h \
    XFileImporter.h \
    XFileParser.h \
    XGLLoader.h \
    XMLTools.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../include


DISTFILES += \
    assimp_dll.pro.user \
    .editorconfig \
    CMakeLists.txt \
    makefile.mingw
