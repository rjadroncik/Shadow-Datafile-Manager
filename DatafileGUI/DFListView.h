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

using namespace SCFBase;
using namespace SCFDatafileIO;

namespace DatafileGUI {

	/// <summary>
	/// Summary for DFListView
	/// </summary>
	public ref class DFListView : public System::Windows::Forms::UserControl
	{
	public:
		DFListView(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DFListView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  view;
	protected: 

	protected: 
	private: System::Windows::Forms::ColumnHeader^  name;
	private: System::Windows::Forms::ColumnHeader^  size;
	private: System::Windows::Forms::ColumnHeader^  attributes;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(DFListView::typeid));
			System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
			System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
			System::Windows::Forms::ToolStripMenuItem^  renameDirectoryToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;
			System::Windows::Forms::ToolStripMenuItem^  createDirectoryToolStripMenuItem;
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator10;
			System::Windows::Forms::ToolStripMenuItem^  addFileToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  addDirectoryToolStripMenuItem;
			this->view = (gcnew System::Windows::Forms::ListView());
			this->name = (gcnew System::Windows::Forms::ColumnHeader());
			this->size = (gcnew System::Windows::Forms::ColumnHeader());
			this->attributes = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->extractToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			renameDirectoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
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
			toolStripMenuItem1->Size = System::Drawing::Size(165, 22);
			toolStripMenuItem1->Text = L"Cu&t";
			// 
			// toolStripMenuItem2
			// 
			toolStripMenuItem2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem2.Image")));
			toolStripMenuItem2->ImageTransparentColor = System::Drawing::Color::Magenta;
			toolStripMenuItem2->Name = L"toolStripMenuItem2";
			toolStripMenuItem2->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			toolStripMenuItem2->Size = System::Drawing::Size(165, 22);
			toolStripMenuItem2->Text = L"&Copy";
			// 
			// toolStripMenuItem3
			// 
			toolStripMenuItem3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem3.Image")));
			toolStripMenuItem3->ImageTransparentColor = System::Drawing::Color::Magenta;
			toolStripMenuItem3->Name = L"toolStripMenuItem3";
			toolStripMenuItem3->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			toolStripMenuItem3->Size = System::Drawing::Size(165, 22);
			toolStripMenuItem3->Text = L"&Paste";
			// 
			// toolStripSeparator7
			// 
			toolStripSeparator7->Name = L"toolStripSeparator7";
			toolStripSeparator7->Size = System::Drawing::Size(162, 6);
			// 
			// renameDirectoryToolStripMenuItem
			// 
			renameDirectoryToolStripMenuItem->Name = L"renameDirectoryToolStripMenuItem";
			renameDirectoryToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			renameDirectoryToolStripMenuItem->Text = L"Rename";
			renameDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFListView::onRename);
			// 
			// removeToolStripMenuItem
			// 
			removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			removeToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			removeToolStripMenuItem->Text = L"Delete";
			removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFListView::onDelete);
			// 
			// toolStripSeparator8
			// 
			toolStripSeparator8->Name = L"toolStripSeparator8";
			toolStripSeparator8->Size = System::Drawing::Size(162, 6);
			// 
			// createDirectoryToolStripMenuItem
			// 
			createDirectoryToolStripMenuItem->Name = L"createDirectoryToolStripMenuItem";
			createDirectoryToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			createDirectoryToolStripMenuItem->Text = L"Create Directory";
			createDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFListView::onDirectoryCreate);
			// 
			// toolStripSeparator10
			// 
			toolStripSeparator10->Name = L"toolStripSeparator10";
			toolStripSeparator10->Size = System::Drawing::Size(162, 6);
			// 
			// addFileToolStripMenuItem
			// 
			addFileToolStripMenuItem->Name = L"addFileToolStripMenuItem";
			addFileToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			addFileToolStripMenuItem->Text = L"Add File(s)";
			addFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFListView::onAddFiles);
			// 
			// addDirectoryToolStripMenuItem
			// 
			addDirectoryToolStripMenuItem->Name = L"addDirectoryToolStripMenuItem";
			addDirectoryToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			addDirectoryToolStripMenuItem->Text = L"Add Directory";
			addDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFListView::onAddDirectory);
			// 
			// view
			// 
			this->view->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {this->name, this->size, this->attributes});
			this->view->ContextMenuStrip = this->contextMenuStrip;
			this->view->Dock = System::Windows::Forms::DockStyle::Fill;
			this->view->FullRowSelect = true;
			this->view->LabelEdit = true;
			this->view->Location = System::Drawing::Point(0, 0);
			this->view->Name = L"view";
			this->view->Size = System::Drawing::Size(529, 441);
			this->view->TabIndex = 6;
			this->view->UseCompatibleStateImageBehavior = false;
			this->view->View = System::Windows::Forms::View::Details;
			this->view->Visible = false;
			this->view->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &DFListView::onMouseDoubleClick);
			this->view->Resize += gcnew System::EventHandler(this, &DFListView::onSize);
			this->view->AfterLabelEdit += gcnew System::Windows::Forms::LabelEditEventHandler(this, &DFListView::onAfterLabelEdit);
			this->view->BeforeLabelEdit += gcnew System::Windows::Forms::LabelEditEventHandler(this, &DFListView::onBeforeLabelEdit);
			// 
			// name
			// 
			this->name->Text = L"Name";
			this->name->Width = 233;
			// 
			// size
			// 
			this->size->Text = L"Size";
			this->size->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->size->Width = 89;
			// 
			// attributes
			// 
			this->attributes->Text = L"Attribs";
			this->attributes->Width = 49;
			// 
			// contextMenuStrip
			// 
			this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {toolStripMenuItem1, 
				toolStripMenuItem2, toolStripMenuItem3, toolStripSeparator7, renameDirectoryToolStripMenuItem, removeToolStripMenuItem, this->extractToolStripMenuItem, 
				toolStripSeparator8, createDirectoryToolStripMenuItem, toolStripSeparator10, addFileToolStripMenuItem, addDirectoryToolStripMenuItem});
			this->contextMenuStrip->Name = L"directoryContextMenuStrip";
			this->contextMenuStrip->Size = System::Drawing::Size(166, 220);
			// 
			// extractToolStripMenuItem
			// 
			this->extractToolStripMenuItem->Name = L"extractToolStripMenuItem";
			this->extractToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->extractToolStripMenuItem->Text = L"Extract";
			this->extractToolStripMenuItem->Click += gcnew System::EventHandler(this, &DFListView::onExtract);
			// 
			// folderBrowserDialog
			// 
			this->folderBrowserDialog->Description = L"Choose a directory to add..";
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"Choose files to add..";
			this->openFileDialog->Filter = L"All files|*.*";
			this->openFileDialog->Multiselect = true;
			this->openFileDialog->ReadOnlyChecked = true;
			this->openFileDialog->ShowReadOnly = true;
			// 
			// DFListView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->view);
			this->Name = L"DFListView";
			this->Size = System::Drawing::Size(529, 441);
			this->contextMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: CDatafile* m_pDatafile;

	public: event DatafileChangedEventHandler^    DatafileChanged; 
	public: event DatafileChangedCWDEventHandler^ DatafileChangedCWD; 

	private: System::Void OnDatafileChanged()
			 {
				 DatafileChanged(this, gcnew EventArgs());
			 }

	private: System::Void OnDatafileChangedCWD()
			 {
				 DatafileChangedCWD(this, gcnew EventArgs());
			 }

	public: System::Void datafileSet(void* pDatafile) {

				m_pDatafile = (CDatafile*)pDatafile;

				if (m_pDatafile != NULL) { view->Visible = TRUE;  }
				else                     { view->Visible = FALSE; }
			}
	private: System::Void onSize(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 view->BeginUpdate();
				 name->Width = __max(100, view->ClientSize.Width - size->Width - attributes->Width);
				 view->EndUpdate();
			 }

	public: System::Void update() {

				view->BeginUpdate();
				view->Items->Clear();

				if (m_pDatafile)
				{
					CDFDirectory Directory(*m_pDatafile, m_pDatafile->CWD());

					if (Directory.Name().Length() != 0)
					{
						ListViewItem^ Item = gcnew ListViewItem("..", 0);
						view->Items->Add(Item);
					}

					CVector<CString> Files;
					CVector<CString> Directories;

					Directory.Read(&Files, &Directories);

					for (UINT i = 0; i < Directories.Size(); i++)
					{
						ListViewItem^ Item = gcnew ListViewItem(gcnew String(Directories[i].Value()), 0);

						Item->SubItems->Add("<DIR>");

						CDFDirectory SubDir(*m_pDatafile, Directory.PathFull(), Directories[i]);

						String^ attributes = gcnew String("");

						if (SubDir.Encrypted()) { attributes += "e"; }
						else                    { attributes += " "; }

						Item->SubItems->Add(attributes);

						Item->ForeColor = Color::Blue;

						view->Items->Add(Item);
					}

					for (UINT i = 0; i < Files.Size(); i++)
					{
						ListViewItem^ Item = gcnew ListViewItem(gcnew String(Files[i].Value()), 0);
						CDFFile File(*m_pDatafile, Directory.PathFull() + Files[i]);
			
						Int64^ sizeValue = gcnew Int64(File.Size());
						String^ size = sizeValue->ToString("### ### ### ###");

						Item->SubItems->Add(size);
						
						String^ attributes = gcnew String("");

						if (File.Encrypted()) { attributes += "e"; }
						else                  { attributes += " "; }
			
						if (File.Compressed()) { attributes += "c"; }
						else                   { attributes += " "; }

						Item->SubItems->Add(attributes);

						view->Items->Add(Item);
					}

					name->Width = __max(100, view->ClientSize.Width - size->Width - attributes->Width);
				}
	
				view->EndUpdate();
			}

private: System::Void onRename(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void onDelete(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void onExtract(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void onDirectoryCreate(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void onAddFiles(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void onAddDirectory(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void onMouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			
			 if (e->Button == System::Windows::Forms::MouseButtons::Left)
			 {
				 if (m_pDatafile)
				 {
					 ListViewItem^ item = view->GetItemAt(e->X, e->Y);

					 if (item != nullptr)
					 {
						 CString csName;
						 StringCopy(csName, item->Text);

						 if (csName == STRING(".."))
						 {
							 CDFDirectory Directory      (*m_pDatafile, m_pDatafile->CWD());
							 CDFDirectory DirectoryParent(*m_pDatafile, Directory.Path());

							 m_pDatafile->CWD(DirectoryParent);

							 OnDatafileChangedCWD();
							 update();
						 }
						 else
						 {
							 if (item->ForeColor == Color::Blue)
							 {
								 CDFDirectory Directory(*m_pDatafile, m_pDatafile->CWD(), csName);

								 m_pDatafile->CWD(Directory);

								 OnDatafileChangedCWD();
								 update();
							 }
						 }
					 }
				 }
			 }
		 }
	private: System::Void onAfterLabelEdit(System::Object^  sender, System::Windows::Forms::LabelEditEventArgs^  e) {
			 }
private: System::Void onBeforeLabelEdit(System::Object^  sender, System::Windows::Forms::LabelEditEventArgs^  e) {
		 }
};
}
