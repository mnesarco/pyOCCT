#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TPrsStd_AISPresentation.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <Quantity_NameOfColor.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_AttributeDelta.hxx>
#include <Standard_Type.hxx>
#include <TPrsStd_AISViewer.hxx>
#include <AIS_InteractiveContext.hxx>
#include <V3d_Viewer.hxx>
#include <Standard_Transient.hxx>
#include <TPrsStd_Driver.hxx>
#include <TPrsStd_AxisDriver.hxx>
#include <TPrsStd_ConstraintDriver.hxx>
#include <TDataXtd_Constraint.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TPrsStd_ConstraintTools.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <TPrsStd_DataMapOfGUIDDriver.hxx>
#include <TPrsStd_DriverTable.hxx>
#include <TPrsStd_GeometryDriver.hxx>
#include <TPrsStd_NamedShapeDriver.hxx>
#include <TPrsStd_PlaneDriver.hxx>
#include <TPrsStd_PointDriver.hxx>

PYBIND11_MODULE(TPrsStd, mod) {

	// IMPORT
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.AIS");
	py::module::import("OCCT.Graphic3d");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.V3d");
	py::module::import("OCCT.TDataXtd");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_AISPresentation.hxx
	py::class_<TPrsStd_AISPresentation, opencascade::handle<TPrsStd_AISPresentation>, TDF_Attribute> cls_TPrsStd_AISPresentation(mod, "TPrsStd_AISPresentation", "An attribute to associate an AIS_InteractiveObject to a label in an AIS viewer. This attribute works in collaboration with TPrsStd_AISViewer. Note that all the Set... and Unset... attribute methods as well as the query methods for visualization attributes and the HasOwn... test methods are shortcuts to the respective AIS_InteractiveObject settings.");
	cls_TPrsStd_AISPresentation.def(py::init<>());
	cls_TPrsStd_AISPresentation.def_static("GetID_", (const Standard_GUID & (*)()) &TPrsStd_AISPresentation::GetID, "Returns the GUID for TPrsStd_AISPresentation attributes.");
	cls_TPrsStd_AISPresentation.def_static("Set_", (opencascade::handle<TPrsStd_AISPresentation> (*)(const TDF_Label &, const Standard_GUID &)) &TPrsStd_AISPresentation::Set, "Creates or retrieves the presentation attribute on the label L, and sets the GUID driver.", py::arg("L"), py::arg("driver"));
	cls_TPrsStd_AISPresentation.def_static("Unset_", (void (*)(const TDF_Label &)) &TPrsStd_AISPresentation::Unset, "Delete (if exist) the presentation attribute associated to the label <L>.", py::arg("L"));
	cls_TPrsStd_AISPresentation.def_static("Set_", (opencascade::handle<TPrsStd_AISPresentation> (*)(const opencascade::handle<TDF_Attribute> &)) &TPrsStd_AISPresentation::Set, "Creates or retrieves the AISPresentation attribute attached to master. The GUID of the driver will be the GUID of master. master is the attribute you want to display.", py::arg("master"));
	cls_TPrsStd_AISPresentation.def("SetDisplayed", (void (TPrsStd_AISPresentation::*)(const Standard_Boolean)) &TPrsStd_AISPresentation::SetDisplayed, "None", py::arg("B"));
	cls_TPrsStd_AISPresentation.def("Display", [](TPrsStd_AISPresentation &self) -> void { return self.Display(); });
	cls_TPrsStd_AISPresentation.def("Display", (void (TPrsStd_AISPresentation::*)(const Standard_Boolean)) &TPrsStd_AISPresentation::Display, "Display presentation of object in AIS viewer. If <update> = True then AISObject is recomputed and all the visualization settings are applied", py::arg("update"));
	cls_TPrsStd_AISPresentation.def("Erase", [](TPrsStd_AISPresentation &self) -> void { return self.Erase(); });
	cls_TPrsStd_AISPresentation.def("Erase", (void (TPrsStd_AISPresentation::*)(const Standard_Boolean)) &TPrsStd_AISPresentation::Erase, "Removes the presentation of this AIS presentation attribute from the TPrsStd_AISViewer. If remove is true, this AIS presentation attribute is removed from the interactive context.", py::arg("remove"));
	cls_TPrsStd_AISPresentation.def("Update", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::Update, "Recompute presentation of object and apply the visualization settings");
	cls_TPrsStd_AISPresentation.def("GetDriverGUID", (Standard_GUID (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::GetDriverGUID, "None");
	cls_TPrsStd_AISPresentation.def("SetDriverGUID", (void (TPrsStd_AISPresentation::*)(const Standard_GUID &)) &TPrsStd_AISPresentation::SetDriverGUID, "None", py::arg("guid"));
	cls_TPrsStd_AISPresentation.def("IsDisplayed", (Standard_Boolean (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::IsDisplayed, "Returns true if this AIS presentation attribute is displayed.");
	cls_TPrsStd_AISPresentation.def("GetAIS", (opencascade::handle<AIS_InteractiveObject> (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::GetAIS, "Returns AIS_InteractiveObject stored in the presentation attribute");
	cls_TPrsStd_AISPresentation.def("Material", (Graphic3d_NameOfMaterial (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::Material, "Returns the material setting for this presentation attribute.");
	cls_TPrsStd_AISPresentation.def("SetMaterial", (void (TPrsStd_AISPresentation::*)(const Graphic3d_NameOfMaterial)) &TPrsStd_AISPresentation::SetMaterial, "Sets the material aName for this presentation attribute.", py::arg("aName"));
	cls_TPrsStd_AISPresentation.def("HasOwnMaterial", (Standard_Boolean (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::HasOwnMaterial, "Returns true if this presentation attribute already has a material setting.");
	cls_TPrsStd_AISPresentation.def("UnsetMaterial", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetMaterial, "Removes the material setting from this presentation attribute.");
	cls_TPrsStd_AISPresentation.def("SetTransparency", [](TPrsStd_AISPresentation &self) -> void { return self.SetTransparency(); });
	cls_TPrsStd_AISPresentation.def("SetTransparency", (void (TPrsStd_AISPresentation::*)(const Standard_Real)) &TPrsStd_AISPresentation::SetTransparency, "Sets the transparency value aValue for this presentation attribute. This value is 0.6 by default.", py::arg("aValue"));
	cls_TPrsStd_AISPresentation.def("Transparency", (Standard_Real (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::Transparency, "None");
	cls_TPrsStd_AISPresentation.def("HasOwnTransparency", (Standard_Boolean (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::HasOwnTransparency, "Returns true if this presentation attribute already has a transparency setting.");
	cls_TPrsStd_AISPresentation.def("UnsetTransparency", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetTransparency, "Removes the transparency setting from this presentation attribute.");
	cls_TPrsStd_AISPresentation.def("Color", (Quantity_NameOfColor (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::Color, "None");
	cls_TPrsStd_AISPresentation.def("SetColor", (void (TPrsStd_AISPresentation::*)(const Quantity_NameOfColor)) &TPrsStd_AISPresentation::SetColor, "Sets the color aColor for this presentation attribute.", py::arg("aColor"));
	cls_TPrsStd_AISPresentation.def("HasOwnColor", (Standard_Boolean (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::HasOwnColor, "Returns true if this presentation attribute already has a color setting.");
	cls_TPrsStd_AISPresentation.def("UnsetColor", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetColor, "Removes the color setting from this presentation attribute.");
	cls_TPrsStd_AISPresentation.def("Width", (Standard_Real (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::Width, "None");
	cls_TPrsStd_AISPresentation.def("SetWidth", (void (TPrsStd_AISPresentation::*)(const Standard_Real)) &TPrsStd_AISPresentation::SetWidth, "Sets the width aWidth for this presentation attribute.", py::arg("aWidth"));
	cls_TPrsStd_AISPresentation.def("HasOwnWidth", (Standard_Boolean (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::HasOwnWidth, "Returns true if this presentation attribute already has a width setting.");
	cls_TPrsStd_AISPresentation.def("UnsetWidth", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetWidth, "Removes the width setting from this presentation attribute.");
	cls_TPrsStd_AISPresentation.def("Mode", (Standard_Integer (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::Mode, "None");
	cls_TPrsStd_AISPresentation.def("SetMode", (void (TPrsStd_AISPresentation::*)(const Standard_Integer)) &TPrsStd_AISPresentation::SetMode, "None", py::arg("theMode"));
	cls_TPrsStd_AISPresentation.def("HasOwnMode", (Standard_Boolean (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::HasOwnMode, "None");
	cls_TPrsStd_AISPresentation.def("UnsetMode", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetMode, "None");
	cls_TPrsStd_AISPresentation.def("SelectionMode", (Standard_Integer (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::SelectionMode, "None");
	cls_TPrsStd_AISPresentation.def("SetSelectionMode", (void (TPrsStd_AISPresentation::*)(const Standard_Integer)) &TPrsStd_AISPresentation::SetSelectionMode, "None", py::arg("theSelectionMode"));
	cls_TPrsStd_AISPresentation.def("HasOwnSelectionMode", (Standard_Boolean (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::HasOwnSelectionMode, "None");
	cls_TPrsStd_AISPresentation.def("UnsetSelectionMode", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::UnsetSelectionMode, "None");
	cls_TPrsStd_AISPresentation.def("ID", (const Standard_GUID & (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::ID, "None");
	cls_TPrsStd_AISPresentation.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::NewEmpty, "None");
	cls_TPrsStd_AISPresentation.def("Restore", (void (TPrsStd_AISPresentation::*)(const opencascade::handle<TDF_Attribute> &)) &TPrsStd_AISPresentation::Restore, "None", py::arg("with"));
	cls_TPrsStd_AISPresentation.def("Paste", (void (TPrsStd_AISPresentation::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TPrsStd_AISPresentation::Paste, "None", py::arg("into"), py::arg("RT"));
	cls_TPrsStd_AISPresentation.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::BackupCopy, "None");
	cls_TPrsStd_AISPresentation.def("AfterAddition", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::AfterAddition, "None");
	cls_TPrsStd_AISPresentation.def("BeforeRemoval", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::BeforeRemoval, "None");
	cls_TPrsStd_AISPresentation.def("BeforeForget", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::BeforeForget, "None");
	cls_TPrsStd_AISPresentation.def("AfterResume", (void (TPrsStd_AISPresentation::*)()) &TPrsStd_AISPresentation::AfterResume, "None");
	cls_TPrsStd_AISPresentation.def("BeforeUndo", [](TPrsStd_AISPresentation &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); }, py::arg("anAttDelta"));
	cls_TPrsStd_AISPresentation.def("BeforeUndo", (Standard_Boolean (TPrsStd_AISPresentation::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TPrsStd_AISPresentation::BeforeUndo, "None", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TPrsStd_AISPresentation.def("AfterUndo", [](TPrsStd_AISPresentation &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); }, py::arg("anAttDelta"));
	cls_TPrsStd_AISPresentation.def("AfterUndo", (Standard_Boolean (TPrsStd_AISPresentation::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TPrsStd_AISPresentation::AfterUndo, "update AIS viewer according to delta", py::arg("anAttDelta"), py::arg("forceIt"));
	cls_TPrsStd_AISPresentation.def_static("get_type_name_", (const char * (*)()) &TPrsStd_AISPresentation::get_type_name, "None");
	cls_TPrsStd_AISPresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_AISPresentation::get_type_descriptor, "None");
	cls_TPrsStd_AISPresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_AISPresentation::*)() const ) &TPrsStd_AISPresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_AISViewer.hxx
	py::class_<TPrsStd_AISViewer, opencascade::handle<TPrsStd_AISViewer>, TDF_Attribute> cls_TPrsStd_AISViewer(mod, "TPrsStd_AISViewer", "The groundwork to define an interactive viewer attribute. This attribute stores an interactive context at the root label. You can only have one instance of this class per data framework.");
	cls_TPrsStd_AISViewer.def(py::init<>());
	cls_TPrsStd_AISViewer.def_static("GetID_", (const Standard_GUID & (*)()) &TPrsStd_AISViewer::GetID, "class methods =============");
	cls_TPrsStd_AISViewer.def_static("Has_", (Standard_Boolean (*)(const TDF_Label &)) &TPrsStd_AISViewer::Has, "returns True if there is an AISViewer attribute in <acces> Data Framework.", py::arg("acces"));
	cls_TPrsStd_AISViewer.def_static("New_", (opencascade::handle<TPrsStd_AISViewer> (*)(const TDF_Label &, const opencascade::handle<AIS_InteractiveContext> &)) &TPrsStd_AISViewer::New, "create and set an AISViewer at. Raise an exception if Has.", py::arg("access"), py::arg("selector"));
	cls_TPrsStd_AISViewer.def_static("New_", (opencascade::handle<TPrsStd_AISViewer> (*)(const TDF_Label &, const opencascade::handle<V3d_Viewer> &)) &TPrsStd_AISViewer::New, "create and set an AISAttribute at root label. The interactive context is build. Raise an exception if Has.", py::arg("acces"), py::arg("viewer"));
	cls_TPrsStd_AISViewer.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TPrsStd_AISViewer> &)) &TPrsStd_AISViewer::Find, "Finds the viewer attribute at the label access, the root of the data framework. Calling this function can be used to initialize an AIS viewer", py::arg("acces"), py::arg("A"));
	cls_TPrsStd_AISViewer.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<AIS_InteractiveContext> &)) &TPrsStd_AISViewer::Find, "None", py::arg("acces"), py::arg("IC"));
	cls_TPrsStd_AISViewer.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<V3d_Viewer> &)) &TPrsStd_AISViewer::Find, "None", py::arg("acces"), py::arg("V"));
	cls_TPrsStd_AISViewer.def_static("Update_", (void (*)(const TDF_Label &)) &TPrsStd_AISViewer::Update, "AISViewer methods =================", py::arg("acces"));
	cls_TPrsStd_AISViewer.def("Update", (void (TPrsStd_AISViewer::*)() const ) &TPrsStd_AISViewer::Update, "Updates the viewer at the label access. access is the root of the data framework.");
	cls_TPrsStd_AISViewer.def("SetInteractiveContext", (void (TPrsStd_AISViewer::*)(const opencascade::handle<AIS_InteractiveContext> &)) &TPrsStd_AISViewer::SetInteractiveContext, "Sets the interactive context ctx for this attribute.", py::arg("ctx"));
	cls_TPrsStd_AISViewer.def("GetInteractiveContext", (opencascade::handle<AIS_InteractiveContext> (TPrsStd_AISViewer::*)() const ) &TPrsStd_AISViewer::GetInteractiveContext, "Returns the interactive context in this attribute.");
	cls_TPrsStd_AISViewer.def("ID", (const Standard_GUID & (TPrsStd_AISViewer::*)() const ) &TPrsStd_AISViewer::ID, "None");
	cls_TPrsStd_AISViewer.def("Restore", (void (TPrsStd_AISViewer::*)(const opencascade::handle<TDF_Attribute> &)) &TPrsStd_AISViewer::Restore, "None", py::arg("with"));
	cls_TPrsStd_AISViewer.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TPrsStd_AISViewer::*)() const ) &TPrsStd_AISViewer::NewEmpty, "None");
	cls_TPrsStd_AISViewer.def("Paste", (void (TPrsStd_AISViewer::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TPrsStd_AISViewer::Paste, "None", py::arg("into"), py::arg("RT"));
	cls_TPrsStd_AISViewer.def_static("get_type_name_", (const char * (*)()) &TPrsStd_AISViewer::get_type_name, "None");
	cls_TPrsStd_AISViewer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_AISViewer::get_type_descriptor, "None");
	cls_TPrsStd_AISViewer.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_AISViewer::*)() const ) &TPrsStd_AISViewer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_Driver.hxx
	py::class_<TPrsStd_Driver, opencascade::handle<TPrsStd_Driver>, Standard_Transient> cls_TPrsStd_Driver(mod, "TPrsStd_Driver", "Driver for AIS ============== An abstract class, which - in classes inheriting from it - allows you to update an AIS_InteractiveObject or create one if one does not already exist. For both creation and update, the interactive object is filled with information contained in attributes. These attributes are those found on the label given as an argument in the method Update. true is returned if the interactive object was modified by the update. This class provide an algorithm to Build with its default values (if Null) or Update (if !Null) an AIS_InteractiveObject . Resources are found in attributes associated to a given label.");
	cls_TPrsStd_Driver.def("Update", (Standard_Boolean (TPrsStd_Driver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_Driver::Update, "Updates the interactive object ais with information found on the attributes associated with the label L.", py::arg("L"), py::arg("ais"));
	cls_TPrsStd_Driver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_Driver::get_type_name, "None");
	cls_TPrsStd_Driver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_Driver::get_type_descriptor, "None");
	cls_TPrsStd_Driver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_Driver::*)() const ) &TPrsStd_Driver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_AxisDriver.hxx
	py::class_<TPrsStd_AxisDriver, opencascade::handle<TPrsStd_AxisDriver>, TPrsStd_Driver> cls_TPrsStd_AxisDriver(mod, "TPrsStd_AxisDriver", "An implementation of TPrsStd_Driver for axes.");
	cls_TPrsStd_AxisDriver.def(py::init<>());
	cls_TPrsStd_AxisDriver.def("Update", (Standard_Boolean (TPrsStd_AxisDriver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_AxisDriver::Update, "Build the AISObject (if null) or update it. No compute is done. Returns <True> if informations was found and AISObject updated.", py::arg("aLabel"), py::arg("anAISObject"));
	cls_TPrsStd_AxisDriver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_AxisDriver::get_type_name, "None");
	cls_TPrsStd_AxisDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_AxisDriver::get_type_descriptor, "None");
	cls_TPrsStd_AxisDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_AxisDriver::*)() const ) &TPrsStd_AxisDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_ConstraintDriver.hxx
	py::class_<TPrsStd_ConstraintDriver, opencascade::handle<TPrsStd_ConstraintDriver>, TPrsStd_Driver> cls_TPrsStd_ConstraintDriver(mod, "TPrsStd_ConstraintDriver", "An implementation of TPrsStd_Driver for constraints.");
	cls_TPrsStd_ConstraintDriver.def(py::init<>());
	cls_TPrsStd_ConstraintDriver.def("Update", (Standard_Boolean (TPrsStd_ConstraintDriver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintDriver::Update, "Build the AISObject (if null) or update it. No compute is done. Returns <True> if informations was found and AISObject updated.", py::arg("aLabel"), py::arg("anAISObject"));
	cls_TPrsStd_ConstraintDriver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_ConstraintDriver::get_type_name, "None");
	cls_TPrsStd_ConstraintDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_ConstraintDriver::get_type_descriptor, "None");
	cls_TPrsStd_ConstraintDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_ConstraintDriver::*)() const ) &TPrsStd_ConstraintDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_ConstraintTools.hxx
	py::class_<TPrsStd_ConstraintTools, std::unique_ptr<TPrsStd_ConstraintTools, Deleter<TPrsStd_ConstraintTools>>> cls_TPrsStd_ConstraintTools(mod, "TPrsStd_ConstraintTools", "None");
	cls_TPrsStd_ConstraintTools.def(py::init<>());
	cls_TPrsStd_ConstraintTools.def_static("UpdateOnlyValue_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, const opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::UpdateOnlyValue, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeDistance_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeDistance, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeParallel_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeParallel, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeTangent_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeTangent, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputePerpendicular_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputePerpendicular, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeConcentric_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeConcentric, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeSymmetry_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeSymmetry, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeMidPoint_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeMidPoint, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeAngle_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeAngle, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeRadius_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeRadius, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeMinRadius_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeMinRadius, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeMaxRadius_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeMaxRadius, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeEqualDistance_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeEqualDistance, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeEqualRadius_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeEqualRadius, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeFix_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeFix, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeDiameter_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeDiameter, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeOffset_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeOffset, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputePlacement_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputePlacement, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeCoincident_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeCoincident, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeRound_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeRound, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeOthers_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeOthers, "None", py::arg("aConst"), py::arg("anAIS"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeTextAndValue_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, Standard_Real &, TCollection_ExtendedString &, const Standard_Boolean)) &TPrsStd_ConstraintTools::ComputeTextAndValue, "None", py::arg("aConst"), py::arg("aValue"), py::arg("aText"), py::arg("anIsAngle"));
	cls_TPrsStd_ConstraintTools.def_static("ComputeAngleForOneFace_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeAngleForOneFace, "None", py::arg("aConst"), py::arg("anAIS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_DriverTable.hxx
	py::class_<TPrsStd_DriverTable, opencascade::handle<TPrsStd_DriverTable>, Standard_Transient> cls_TPrsStd_DriverTable(mod, "TPrsStd_DriverTable", "This class is a container to record (AddDriver) binding between GUID and TPrsStd_Driver. You create a new instance of TPrsStd_Driver and use the method AddDriver to load it into the driver table. the method");
	cls_TPrsStd_DriverTable.def(py::init<>());
	cls_TPrsStd_DriverTable.def_static("Get_", (opencascade::handle<TPrsStd_DriverTable> (*)()) &TPrsStd_DriverTable::Get, "Returns the static table. If it does not exist, creates it and fills it with standard drivers.");
	cls_TPrsStd_DriverTable.def("InitStandardDrivers", (void (TPrsStd_DriverTable::*)()) &TPrsStd_DriverTable::InitStandardDrivers, "Fills the table with standard drivers");
	cls_TPrsStd_DriverTable.def("AddDriver", (Standard_Boolean (TPrsStd_DriverTable::*)(const Standard_GUID &, const opencascade::handle<TPrsStd_Driver> &)) &TPrsStd_DriverTable::AddDriver, "Returns true if the driver has been added successfully to the driver table.", py::arg("guid"), py::arg("driver"));
	cls_TPrsStd_DriverTable.def("FindDriver", (Standard_Boolean (TPrsStd_DriverTable::*)(const Standard_GUID &, opencascade::handle<TPrsStd_Driver> &) const ) &TPrsStd_DriverTable::FindDriver, "Returns true if the driver was found.", py::arg("guid"), py::arg("driver"));
	cls_TPrsStd_DriverTable.def("RemoveDriver", (Standard_Boolean (TPrsStd_DriverTable::*)(const Standard_GUID &)) &TPrsStd_DriverTable::RemoveDriver, "Removes a driver with the given GUID. Returns true if the driver has been removed successfully.", py::arg("guid"));
	cls_TPrsStd_DriverTable.def("Clear", (void (TPrsStd_DriverTable::*)()) &TPrsStd_DriverTable::Clear, "Removes all drivers. Returns true if the driver has been removed successfully. If this method is used, the InitStandardDrivers method should be called to fill the table with standard drivers.");
	cls_TPrsStd_DriverTable.def_static("get_type_name_", (const char * (*)()) &TPrsStd_DriverTable::get_type_name, "None");
	cls_TPrsStd_DriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_DriverTable::get_type_descriptor, "None");
	cls_TPrsStd_DriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_DriverTable::*)() const ) &TPrsStd_DriverTable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_GeometryDriver.hxx
	py::class_<TPrsStd_GeometryDriver, opencascade::handle<TPrsStd_GeometryDriver>, TPrsStd_Driver> cls_TPrsStd_GeometryDriver(mod, "TPrsStd_GeometryDriver", "This method is an implementation of TPrsStd_Driver for geometries.");
	cls_TPrsStd_GeometryDriver.def(py::init<>());
	cls_TPrsStd_GeometryDriver.def("Update", (Standard_Boolean (TPrsStd_GeometryDriver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_GeometryDriver::Update, "Build the AISObject (if null) or update it. No compute is done. Returns <True> if informations was found and AISObject updated.", py::arg("aLabel"), py::arg("anAISObject"));
	cls_TPrsStd_GeometryDriver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_GeometryDriver::get_type_name, "None");
	cls_TPrsStd_GeometryDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_GeometryDriver::get_type_descriptor, "None");
	cls_TPrsStd_GeometryDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_GeometryDriver::*)() const ) &TPrsStd_GeometryDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_NamedShapeDriver.hxx
	py::class_<TPrsStd_NamedShapeDriver, opencascade::handle<TPrsStd_NamedShapeDriver>, TPrsStd_Driver> cls_TPrsStd_NamedShapeDriver(mod, "TPrsStd_NamedShapeDriver", "An implementation of TPrsStd_Driver for named shapes.");
	cls_TPrsStd_NamedShapeDriver.def(py::init<>());
	cls_TPrsStd_NamedShapeDriver.def("Update", (Standard_Boolean (TPrsStd_NamedShapeDriver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_NamedShapeDriver::Update, "Build the AISObject (if null) or update it. No compute is done. Returns <True> if informations was found and AISObject updated.", py::arg("aLabel"), py::arg("anAISObject"));
	cls_TPrsStd_NamedShapeDriver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_NamedShapeDriver::get_type_name, "None");
	cls_TPrsStd_NamedShapeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_NamedShapeDriver::get_type_descriptor, "None");
	cls_TPrsStd_NamedShapeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_NamedShapeDriver::*)() const ) &TPrsStd_NamedShapeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_PlaneDriver.hxx
	py::class_<TPrsStd_PlaneDriver, opencascade::handle<TPrsStd_PlaneDriver>, TPrsStd_Driver> cls_TPrsStd_PlaneDriver(mod, "TPrsStd_PlaneDriver", "An implementation of TPrsStd_Driver for planes.");
	cls_TPrsStd_PlaneDriver.def(py::init<>());
	cls_TPrsStd_PlaneDriver.def("Update", (Standard_Boolean (TPrsStd_PlaneDriver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_PlaneDriver::Update, "Build the AISObject (if null) or update it. No compute is done. Returns <True> if informations was found and AISObject updated.", py::arg("aLabel"), py::arg("anAISObject"));
	cls_TPrsStd_PlaneDriver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_PlaneDriver::get_type_name, "None");
	cls_TPrsStd_PlaneDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_PlaneDriver::get_type_descriptor, "None");
	cls_TPrsStd_PlaneDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_PlaneDriver::*)() const ) &TPrsStd_PlaneDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_PointDriver.hxx
	py::class_<TPrsStd_PointDriver, opencascade::handle<TPrsStd_PointDriver>, TPrsStd_Driver> cls_TPrsStd_PointDriver(mod, "TPrsStd_PointDriver", "An implementation of TPrsStd_Driver for points.");
	cls_TPrsStd_PointDriver.def(py::init<>());
	cls_TPrsStd_PointDriver.def("Update", (Standard_Boolean (TPrsStd_PointDriver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_PointDriver::Update, "Build the AISObject (if null) or update it. No compute is done. Returns <True> if informations was found and AISObject updated.", py::arg("aLabel"), py::arg("anAISObject"));
	cls_TPrsStd_PointDriver.def_static("get_type_name_", (const char * (*)()) &TPrsStd_PointDriver::get_type_name, "None");
	cls_TPrsStd_PointDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_PointDriver::get_type_descriptor, "None");
	cls_TPrsStd_PointDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_PointDriver::*)() const ) &TPrsStd_PointDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TPrsStd_DataMapOfGUIDDriver, std::unique_ptr<TPrsStd_DataMapOfGUIDDriver, Deleter<TPrsStd_DataMapOfGUIDDriver>>, NCollection_BaseMap> cls_TPrsStd_DataMapOfGUIDDriver(mod, "TPrsStd_DataMapOfGUIDDriver", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TPrsStd_DataMapOfGUIDDriver.def(py::init<>());
	cls_TPrsStd_DataMapOfGUIDDriver.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TPrsStd_DataMapOfGUIDDriver.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TPrsStd_DataMapOfGUIDDriver.def(py::init([] (const TPrsStd_DataMapOfGUIDDriver &other) {return new TPrsStd_DataMapOfGUIDDriver(other);}), "Copy constructor", py::arg("other"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("begin", (TPrsStd_DataMapOfGUIDDriver::iterator (TPrsStd_DataMapOfGUIDDriver::*)() const ) &TPrsStd_DataMapOfGUIDDriver::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TPrsStd_DataMapOfGUIDDriver.def("end", (TPrsStd_DataMapOfGUIDDriver::iterator (TPrsStd_DataMapOfGUIDDriver::*)() const ) &TPrsStd_DataMapOfGUIDDriver::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TPrsStd_DataMapOfGUIDDriver.def("cbegin", (TPrsStd_DataMapOfGUIDDriver::const_iterator (TPrsStd_DataMapOfGUIDDriver::*)() const ) &TPrsStd_DataMapOfGUIDDriver::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TPrsStd_DataMapOfGUIDDriver.def("cend", (TPrsStd_DataMapOfGUIDDriver::const_iterator (TPrsStd_DataMapOfGUIDDriver::*)() const ) &TPrsStd_DataMapOfGUIDDriver::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TPrsStd_DataMapOfGUIDDriver.def("Exchange", (void (TPrsStd_DataMapOfGUIDDriver::*)(TPrsStd_DataMapOfGUIDDriver &)) &TPrsStd_DataMapOfGUIDDriver::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("Assign", (TPrsStd_DataMapOfGUIDDriver & (TPrsStd_DataMapOfGUIDDriver::*)(const TPrsStd_DataMapOfGUIDDriver &)) &TPrsStd_DataMapOfGUIDDriver::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("assign", (TPrsStd_DataMapOfGUIDDriver & (TPrsStd_DataMapOfGUIDDriver::*)(const TPrsStd_DataMapOfGUIDDriver &)) &TPrsStd_DataMapOfGUIDDriver::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("ReSize", (void (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_Integer)) &TPrsStd_DataMapOfGUIDDriver::ReSize, "ReSize", py::arg("N"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("Bind", (Standard_Boolean (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &, const opencascade::handle<TPrsStd_Driver> &)) &TPrsStd_DataMapOfGUIDDriver::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TPrsStd_DataMapOfGUIDDriver.def("Bound", (opencascade::handle<TPrsStd_Driver> * (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &, const opencascade::handle<TPrsStd_Driver> &)) &TPrsStd_DataMapOfGUIDDriver::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("IsBound", (Standard_Boolean (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &) const ) &TPrsStd_DataMapOfGUIDDriver::IsBound, "IsBound", py::arg("theKey"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("UnBind", (Standard_Boolean (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &)) &TPrsStd_DataMapOfGUIDDriver::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TPrsStd_DataMapOfGUIDDriver.def("Seek", (const opencascade::handle<TPrsStd_Driver> * (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &) const ) &TPrsStd_DataMapOfGUIDDriver::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TPrsStd_DataMapOfGUIDDriver.def("Find", (const opencascade::handle<TPrsStd_Driver> & (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &) const ) &TPrsStd_DataMapOfGUIDDriver::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TPrsStd_DataMapOfGUIDDriver.def("Find", (Standard_Boolean (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &, opencascade::handle<TPrsStd_Driver> &) const ) &TPrsStd_DataMapOfGUIDDriver::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("__call__", (const opencascade::handle<TPrsStd_Driver> & (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &) const ) &TPrsStd_DataMapOfGUIDDriver::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TPrsStd_DataMapOfGUIDDriver.def("ChangeSeek", (opencascade::handle<TPrsStd_Driver> * (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &)) &TPrsStd_DataMapOfGUIDDriver::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("ChangeFind", (opencascade::handle<TPrsStd_Driver> & (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &)) &TPrsStd_DataMapOfGUIDDriver::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("__call__", (opencascade::handle<TPrsStd_Driver> & (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_GUID &)) &TPrsStd_DataMapOfGUIDDriver::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("Clear", [](TPrsStd_DataMapOfGUIDDriver &self) -> void { return self.Clear(); });
	cls_TPrsStd_DataMapOfGUIDDriver.def("Clear", (void (TPrsStd_DataMapOfGUIDDriver::*)(const Standard_Boolean)) &TPrsStd_DataMapOfGUIDDriver::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("Clear", (void (TPrsStd_DataMapOfGUIDDriver::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TPrsStd_DataMapOfGUIDDriver::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TPrsStd_DataMapOfGUIDDriver.def("Size", (Standard_Integer (TPrsStd_DataMapOfGUIDDriver::*)() const ) &TPrsStd_DataMapOfGUIDDriver::Size, "Size");
	cls_TPrsStd_DataMapOfGUIDDriver.def("__iter__", [](const TPrsStd_DataMapOfGUIDDriver &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TPrsStd_DataMapOfGUIDDriver.hxx

}