#pragma once

#pragma managed(push, off)

#include <SCFObjectExtensions.h>
#include <SCFDatafileIO.h>

#pragma managed(pop)

#include <SCFInteropCLI.h>

#include "Events.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace SCF;
using namespace SCFBase;
using namespace SCFDatafileIO;

namespace DatafileGUI {

	/// <summary>
	/// Summary for DFTreeView
	/// </summary>
	public ref class DFTreeView : public System::Windows::Forms::UserControl
	{

	public: DFTreeView(void) : m_pDatafile(NULL)
	{
		InitializeComponent();
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DFTreeView()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TreeView^  view;


	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  extractToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(DFTreeView::typeid));
			System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
			System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
			System::Windows::Forms::ToolStripMenuItem^  renameDirectoryToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  createDirectoryToolStripMenuItem;
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator10;
			System::Windows::Forms::ToolStripMenuItem^  addFileToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  addDirectoryToolStripMenuItem;
			this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->extractToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->view = (gcnew System::Windows::Forms::TreeView());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			renameDirectoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			createDirectoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripSeparator10 = (gcnew System::Windows::Forms::ToolStripSeparator());
			addFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			addDirectoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStripMenuItem1
			// 
			toolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem1.Image")));
			toolStripMenuItem1->ImageTransparentColor = System::Drawing::Color::Magenta;
			toolStripMenuItem1->Name = L"toolStripMenuItem1";
			toolStripMenuItem1->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			toolStripMenuItem1->Size = System::Drawing::Size(152, 22);
			toolStripMenuItem1->Text = L"Cu&t";
			// 
			// toolStripMenuItem2
			// 
			toolStripMenuItem2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem2.Image")));
			toolStripMenuItem2->ImageTransparentColor = System::Drawing::Color::Magenta;
			toolStripMenuItem2->Name = L"toolStripMenuItem2";
			toolStripMenuItem2->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			toolStripMenuItem2->Size = System::Drawing::Size(152, 22);
			toolStripMenuItem2->Text = L"&Copy";
			// 
			// toolStripMenuItem3
			// 
			toolStripMenuItem3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem3.Image")));
			toolStripMenuItem3->ImageTransparentColor = System::Drawing::Color::Magenta;
			toolStripMenuItem3->Name = L"toolStripMenuItem3";
			toolStripMenuItem3->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			toolStripMenuItem3->Size = System::Drawing::Size(152, 22);
			toolStripMenuItem3->Text = L"&Paste";
			// 
			// toolStripSeparator7
			// 
			toolStripSeparator7->Name = L"toolStripSeparator7";
			toolStripSeparator7->Size = System::Drawing::Size(149, 6);
			// 
			// renameDirectoryToolStripMenuItem
			// 
			renameDirectoryToolStripMenuItem->Name = L"renameDirectoryToolStripMenuItem";
			renameDirectoryToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			renameDirectoryToolStripMenuItem->Text = L"Rename";
			renameDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFTreeView::onDirectoryRename);
			// 
			// removeToolStripMenuItem
			// 
			removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			removeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			removeToolStripMenuItem->Text = L"Delete";
			removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFTreeView::onDirectoryDelete);
			// 
			// createDirectoryToolStripMenuItem
			// 
			createDirectoryToolStripMenuItem->Name = L"createDirectoryToolStripMenuItem";
			createDirectoryToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			createDirectoryToolStripMenuItem->Text = L"Create";
			createDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFTreeView::onDirectoryCreate);
			// 
			// toolStripSeparator10
			// 
			toolStripSeparator10->Name = L"toolStripSeparator10";
			toolStripSeparator10->Size = System::Drawing::Size(149, 6);
			// 
			// addFileToolStripMenuItem
			// 
			addFileToolStripMenuItem->Name = L"addFileToolStripMenuItem";
			addFileToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			addFileToolStripMenuItem->Text = L"Add File(s)";
			addFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFTreeView::onFilesAdd);
			// 
			// addDirectoryToolStripMenuItem
			// 
			addDirectoryToolStripMenuItem->Name = L"addDirectoryToolStripMenuItem";
			addDirectoryToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			addDirectoryToolStripMenuItem->Text = L"Add Directory";
			addDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFTreeView::onDirectoryAdd);
			// 
			// contextMenuStrip
			// 
			this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {toolStripMenuItem1, 
				toolStripMenuItem2, toolStripMenuItem3, toolStripSeparator7, createDirectoryToolStripMenuItem, renameDirectoryToolStripMenuItem, 
				removeToolStripMenuItem, this->extractToolStripMenuItem, toolStripSeparator10, addFileToolStripMenuItem, addDirectoryToolStripMenuItem});
			this->contextMenuStrip->Name = L"directoryContextMenuStrip";
			this->contextMenuStrip->Size = System::Drawing::Size(153, 236);
			// 
			// extractToolStripMenuItem
			// 
			this->extractToolStripMenuItem->Name = L"extractToolStripMenuItem";
			this->extractToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->extractToolStripMenuItem->Text = L"Extract";
			this->extractToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFTreeView::onDirectoryExtract);
			// 
			// view
			// 
			this->view->Dock = System::Windows::Forms::DockStyle::Fill;
			this->view->HideSelection = false;
			this->view->LabelEdit = true;
			this->view->Location = System::Drawing::Point(0, 0);
			this->view->Name = L"view";
			this->view->Size = System::Drawing::Size(465, 424);
			this->view->TabIndex = 3;
			this->view->Visible = false;
			this->view->AfterLabelEdit += gcnew System::Windows::Forms::NodeLabelEditEventHandler(this, &DFTreeView::onAfterLabelEdit);
			this->view->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &DFTreeView::onAfterSelect);
			this->view->NodeMouseClick += gcnew System::Windows::Forms::TreeNodeMouseClickEventHandler(this, &DFTreeView::onNodeMouseClick);
			this->view->BeforeLabelEdit += gcnew System::Windows::Forms::NodeLabelEditEventHandler(this, &DFTreeView::onBeforeLabelEdit);
			// 
			// folderBrowserDialog
			// 
			this->folderBrowserDialog->Description = L"Choose a directory..";
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"Choose files..";
			this->openFileDialog->Filter = L"All files|*.*";
			this->openFileDialog->Multiselect = true;
			this->openFileDialog->ReadOnlyChecked = true;
			this->openFileDialog->ShowReadOnly = true;
			// 
			// DFTreeView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->view);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"DFTreeView";
			this->Size = System::Drawing::Size(465, 424);
			this->contextMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		CDatafile* m_pDatafile;
		bool m_bEditingNewNode;

	public: event DatafileChangedEventHandler^    DatafileChanged; 
	public: event DatafileChangedCWDEventHandler^ DatafileChangedCWD; 

	private: System::Void RaiseDatafileChanged()    { if (&DFTreeView::DatafileChanged    != nullptr) { DatafileChanged   (this, gcnew EventArgs()); } }
	private: System::Void RaiseDatafileChangedCWD() { if (&DFTreeView::DatafileChangedCWD != nullptr) { DatafileChangedCWD(this, gcnew EventArgs()); } }

	public: System::Void datafileSet(void* pDatafile) {

				m_pDatafile = (CDatafile*)pDatafile;

				if (m_pDatafile != NULL) { view->Visible = TRUE;  }
				else                     { view->Visible = FALSE; }

				rebuild();
			}

	public: System::Void update() {

				if (m_pDatafile)
				{
					String^ path = gcnew String(m_pDatafile->CWD().Value());

					int iStart = 1;
					TreeNode^ node = view->Nodes[0];

					while (iStart < path->Length)
					{
						int iEnd = path->IndexOf('\\', iStart);

						String^ name = path->Substring(iStart, iEnd - iStart);

						for (int i = 0; i < node->Nodes->Count; i++)
						{
							if (name->CompareTo(node->Nodes[i]->Text) == 0)
							{
								iStart = (UINT)iEnd + 1;
								node = node->Nodes[i];
								break;
							}
						}
					}

					view->SelectedNode = node;
				}
			}

	private: System::Void rebuild() {

				 view->BeginUpdate();
				 view->Nodes->Clear();

				 if (m_pDatafile)
				 {
					 CDFDirectory Directory(*m_pDatafile, STRING("\\"));

					 TreeNode^ NewNode = gcnew TreeNode(gcnew String("{root}"));
					 view->Nodes->Add(NewNode);

					 nodesBuild(Directory, NewNode);

					 view->Nodes[0]->Expand();
				 }
				 view->EndUpdate();
			 }

	private: System::Void nodesBuild(_IN CDFDirectory& rDirectory, TreeNode^ node) {

				 CVector<CString> Directories;
				 rDirectory.Read(NULL, &Directories);

				 for (UINT i = 0; i < Directories.Size(); i++)
				 {
					 CDFDirectory Directory(rDirectory.Datafile(), rDirectory.PathFull() + (CString&)(Directories[i]) + STRING("\\"));

					 TreeNode^ NewNode = gcnew TreeNode(gcnew String(((CString&)(Directories[i])).Value()));
					 node->Nodes->Add(NewNode);

					 nodesBuild(Directory, NewNode);
				 }

				 Directories.AllDelete();
			 }

	private: System::Void onDirectoryDelete(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (view->SelectedNode == view->Nodes[0]) { return; }

				 String^ fullPath = fullPathFor(view->SelectedNode, "");

				 CString csFullPath;
				 StringCopy(csFullPath, fullPath);

				 CDFDirectory Directory(*m_pDatafile, csFullPath);

				 if (Directory.Exists())
				 {
					 if (Directory.Delete())
					 {
						 view->Nodes->Remove(view->SelectedNode);
						 RaiseDatafileChanged();
					 }
					 else
					 {
						 MessageBox::Show("Could not remove directory. ", "Error while removing directory.", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }
				 }
				 else
				 {
					 MessageBox::Show("The specified directory does not exist.", "Error while removing directory.", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 view->Nodes->Remove(view->SelectedNode);
				 }
			 }

	private: System::Void onDirectoryRename(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (view->SelectedNode == view->Nodes[0]) { return; }

				 m_bEditingNewNode = FALSE;
				 view->SelectedNode->BeginEdit();
			 }

	private: System::Void onDirectoryExtract(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (folderBrowserDialog->ShowDialog() ==  System::Windows::Forms::DialogResult::OK)
				 {
					 CString DFPath;
					 StringCopy(DFPath, fullPathFor(view->SelectedNode, ""));
			
					 CDFDirectory DFDirectory(*m_pDatafile, DFPath);

					 CString Path;
					 StringCopy(Path, folderBrowserDialog->SelectedPath);

					 //Terminate path
					 if ((Path[Path.Length() - 1] != '/') && (Path[Path.Length() - 1] != '\\')) { Path += '\\'; }

					 CString Name;
					 StringCopy(Name, view->SelectedNode->Text);

					 Path += Name;
					 Path += '\\';

					 CDirectory Dir(Path);
					 if (Dir.Exists())
					 {
						 DialogResult result = MessageBox::Show("The target directory already exists.\nShould it's contents be overwritten?", "Warning, target directory already exists.", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);

						 if (result == DialogResult::Yes) 
						 {
							 DFDirectory.Copy(Dir, TRUE);
						 }
						 if (result == DialogResult::No) 
						 {
							 DFDirectory.Copy(Dir, FALSE); 
						 }
					 }
					 else { DFDirectory.Copy(Dir); }
				 }
			 }

	private: System::Void onDirectoryCreate(System::Object^ sender, System::EventArgs^ e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 TreeNode^ NewNode = gcnew TreeNode(gcnew String(""));

				 view->SelectedNode->Nodes->Add(NewNode);
				 view->SelectedNode = NewNode; 

				 m_bEditingNewNode = TRUE;
				 view->SelectedNode->BeginEdit();
			 }

	private: System::Void onFilesAdd(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (openFileDialog->ShowDialog() ==  System::Windows::Forms::DialogResult::OK)
				 {
					 CString csDFDirPath;
					 String^ DFDirPath = fullPathFor(view->SelectedNode, "");
					 StringCopy(csDFDirPath, DFDirPath);

					 CDFDirectory DFDir(*m_pDatafile, csDFDirPath);

					 for (int i = 0; i < openFileDialog->FileNames->Length; i++)
					 {
						 CString csFilePath;
						 StringCopy(csFilePath, openFileDialog->FileNames[i]);

						 CFile File(csFilePath);

						 CDFFile DFFile(*m_pDatafile, DFDir.PathFull() + File.NameFull());
						 DFFile.Create(File);
					 }
					 RaiseDatafileChanged();
				 }
			 }

	private: System::Void onDirectoryAdd(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (folderBrowserDialog->ShowDialog() ==  System::Windows::Forms::DialogResult::OK)
				 {
					 CString Path;
					 StringCopy(Path, folderBrowserDialog->SelectedPath);
		
					 //Terminate path
					 if ((Path[Path.Length() - 1] != '/') && (Path[Path.Length() - 1] != '\\')) { Path += '\\'; }

					 CDirectory Dir(Path);
					 if (Dir.Exists())
					 {
						 CString DFPath;
						 StringCopy(DFPath, fullPathFor(view->SelectedNode, ""));

						 directoryAdd(Dir, DFPath, view->SelectedNode);
					 }
					 else
					 {
						 MessageBox::Show("The specified directory could not be added.", "Error while adding directory.", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }
				 }
			 }

	private: System::Void directoryAdd(_IN CDirectory& rDirectory, _IN CString& rDFParentPath, TreeNode^ parentNode) {

				 CDFDirectory DFDir(*m_pDatafile, rDFParentPath + rDirectory.Name() + '\\');
				 if (DFDir.Create(TRUE))
				 {
					 TreeNode^ node = gcnew TreeNode(gcnew String(DFDir.Name().Value()));
					 parentNode->Nodes->Add(node);

					 CVector<CString> Files;
					 CVector<CString> Directories;

					 rDirectory.Read(&Files, &Directories);

					 for (UINT i = 0; i < Files.Size(); i++)
					 {
						 CFile File(rDirectory.PathFull() + Files[i]);

						 CDFFile DFFile(*m_pDatafile, DFDir.PathFull() + Files[i]);
						 DFFile.Create(File);
					 }
					 Files.AllDelete();

					 for (UINT i = 0; i < Directories.Size(); i++)
					 {
						 CDirectory SubDir(rDirectory.PathFull() + Directories[i] + STRING("\\"));

						 directoryAdd(SubDir, DFDir.PathFull(), node);
					 }
					 Directories.AllDelete();

					 RaiseDatafileChanged();
				 }
				 else
				 {
					 MessageBox::Show("The directory could not be created at the specified location in the datafile.", "Error while adding directory.", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			 }

	private: System::Boolean nameCheck(String^ name) {

				 array<Char>^ chars = {'/','\\'};

				 if (name->IndexOfAny(chars) == -1) { return true; }
				 else                               { return false; }
			 }

	private: System::String^ fullPathFor(TreeNode^ node, String^ pathEnd) {
			  
				 if (node->Parent != nullptr) { return fullPathFor(node->Parent, node->Text + "\\" + pathEnd); }
				 else                         { return "\\" + pathEnd; }
			 }

	private: System::Void onAfterLabelEdit(System::Object^  sender, System::Windows::Forms::NodeLabelEditEventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (m_bEditingNewNode)
				 {
					 if (e->Label != nullptr)
					 {
						 if (!nameCheck(e->Label))
						 {
							 e->CancelEdit = true;
							 e->Node->Text = e->Label;
							 MessageBox::Show("The name you entered contained one of the following illegal characters: '/\\'.", "Bad directory name.", MessageBoxButtons::OK, MessageBoxIcon::Error);
							 e->Node->BeginEdit();
						 }
						 else
						 {
							 String^ fullPath = fullPathFor(e->Node->Parent, e->Label + "\\");

							 CString csFullPath;
							 StringCopy(csFullPath, fullPath);

							 CDFDirectory Directory(*m_pDatafile, csFullPath);
							 if (Directory.Exists())
							 {
								 e->CancelEdit = true;
								 e->Node->Text = e->Label;
								 MessageBox::Show("The name you entered is already in use.", "Duplicate directory name.", MessageBoxButtons::OK, MessageBoxIcon::Error);
								 e->Node->BeginEdit();
							 }
							 else
							 {
								 if (Directory.Create()) 
								 { 
									 m_pDatafile->CWD(csFullPath);
								
									 //Fire events
									 RaiseDatafileChangedCWD();
									 RaiseDatafileChanged(); 
								 }
								 else
								 {
									 MessageBox::Show("Could not create a directory.", "Error while creating directory.", MessageBoxButtons::OK, MessageBoxIcon::Error);
									 e->Node->Parent->Nodes->Remove(e->Node); 
								 }

								 m_bEditingNewNode = FALSE;
							 }
						 }
					 }
					 else { e->Node->Parent->Nodes->Remove(e->Node); }
				 }
				 else
				 {
					 if (e->Label != nullptr)
					 {
						 if (!nameCheck(e->Label))
						 {
							 e->CancelEdit = true;
							 e->Node->Text = e->Label;
							 MessageBox::Show("The name you entered contained one of the following illegal characters: '/\\'.", "Bad directory name.", MessageBoxButtons::OK, MessageBoxIcon::Error);
							 e->Node->BeginEdit();
						 }
						 else
						 {
							 String^ fullPath = fullPathFor(e->Node->Parent, e->Label + "\\");

							 CString csFullPath;
							 StringCopy(csFullPath, fullPath);

							 CDFDirectory Directory(*m_pDatafile, csFullPath);
							 if (!Directory.Exists())
							 {
								 CDFDirectory DirectoryOld(*m_pDatafile, m_pDatafile->CWD());

								 CString csNewName;
								 StringCopy(csNewName, e->Label);

								 if (DirectoryOld.Rename(csNewName)) 
								 {
									 m_pDatafile->CWD(csFullPath);

									 //Fire events
									 RaiseDatafileChangedCWD();
									 RaiseDatafileChanged();
								 }
								 else
								 {
									 MessageBox::Show("Could not rename directory.", "Error while renaming directory.", MessageBoxButtons::OK, MessageBoxIcon::Error);
									 e->Node->Parent->Nodes->Remove(e->Node); 
								 }
							 }
							 else
							 {
								 e->CancelEdit = true;
								 e->Node->Text = e->Label;
								 MessageBox::Show("The name you entered is already in use.", "Duplicate directory name.", MessageBoxButtons::OK, MessageBoxIcon::Error);
								 e->Node->BeginEdit();
							 }
						 }
					 }
				 }
			 }

	private: System::Void onNodeMouseClick(System::Object^  sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (e->Button == System::Windows::Forms::MouseButtons::Right)
				 {
					 view->SelectedNode = e->Node;
					 contextMenuStrip->Show(view, e->Location);					 
				 }
			 }
	private: System::Void onAfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(sender);
				
				 String^ path = fullPathFor(e->Node, "");
				 CString csPath;

				 StringCopy(csPath, path);
				 m_pDatafile->CWD(csPath);

				 if (!(e->Node->Text == ""))
				 {
					 //Fire event
					 RaiseDatafileChangedCWD();
				 }
			 }
	private: System::Void onBeforeLabelEdit(System::Object^  sender, System::Windows::Forms::NodeLabelEditEventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (view->SelectedNode == view->Nodes[0]) { e->CancelEdit = TRUE; }
			 }
};
}
