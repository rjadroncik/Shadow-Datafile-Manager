#pragma once

#pragma managed(push, off)

#include <SCFObjectExtensions.h>
#include <SCFDatafileIO.h>

#pragma managed(pop)

#include <SCFInteropCLI.h>

namespace ShadowDatafileManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace SCFBase;
	using namespace SCFDatafileIO;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		FormMain(void)
			: m_pDatafile(NULL), m_bDatafileChanged(FALSE), m_pDatafilePath(NULL), splitValue(0.5f)
		{
			ToolStripManager::RenderMode = ToolStripManagerRenderMode::Professional;  

			InitializeComponent();

			splitValue = (float)treeView->Width / (float)this->Width;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Splitter^  splitter;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  selectAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripButton^  toolStripFileSave;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	private: DatafileGUI::DFTreeView^  treeView;
	private: System::Windows::Forms::ColumnHeader^  name;
	private: System::Windows::Forms::ColumnHeader^  size;
	private: System::Windows::Forms::ColumnHeader^  attributes;
	private: DatafileGUI::DFListView^  listView;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabelCWDValue;
	private: System::Windows::Forms::ToolStrip^  toolStrip;
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
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
			System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabelCWDLabel;
			System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
			System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
			System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  customizeToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  datafileToolStripMenuItem;
			System::Windows::Forms::ToolStripButton^  toolStripFileNew;
			System::Windows::Forms::ToolStripButton^  toolStripFileOpen;
			System::Windows::Forms::StatusStrip^  statusStrip;
			System::Windows::Forms::MenuStrip^  menuStrip;
			System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  contentsToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  indexToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  searchToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->selectAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripStatusLabelCWDValue = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripFileSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->splitter = (gcnew System::Windows::Forms::Splitter());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->name = (gcnew System::Windows::Forms::ColumnHeader());
			this->size = (gcnew System::Windows::Forms::ColumnHeader());
			this->attributes = (gcnew System::Windows::Forms::ColumnHeader());
			this->listView = (gcnew DatafileGUI::DFListView());
			this->treeView = (gcnew DatafileGUI::DFTreeView());
			toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			toolStripStatusLabelCWDLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			customizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			datafileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripFileNew = (gcnew System::Windows::Forms::ToolStripButton());
			toolStripFileOpen = (gcnew System::Windows::Forms::ToolStripButton());
			statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			contentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			indexToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			statusStrip->SuspendLayout();
			menuStrip->SuspendLayout();
			this->toolStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStripSeparator4
			// 
			toolStripSeparator4->Name = L"toolStripSeparator4";
			toolStripSeparator4->Size = System::Drawing::Size(147, 6);
			// 
			// toolStripStatusLabelCWDLabel
			// 
			toolStripStatusLabelCWDLabel->Name = L"toolStripStatusLabelCWDLabel";
			toolStripStatusLabelCWDLabel->Size = System::Drawing::Size(35, 17);
			toolStripStatusLabelCWDLabel->Text = L"CWD:";
			// 
			// fileToolStripMenuItem
			// 
			fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {newToolStripMenuItem, 
				openToolStripMenuItem, toolStripSeparator, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, toolStripSeparator2, exitToolStripMenuItem});
			fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			fileToolStripMenuItem->Text = L"&File";
			// 
			// newToolStripMenuItem
			// 
			newToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newToolStripMenuItem.Image")));
			newToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			newToolStripMenuItem->Name = L"newToolStripMenuItem";
			newToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			newToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			newToolStripMenuItem->Text = L"&New";
			newToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::datafileNew);
			// 
			// openToolStripMenuItem
			// 
			openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripMenuItem.Image")));
			openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			openToolStripMenuItem->Name = L"openToolStripMenuItem";
			openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			openToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			openToolStripMenuItem->Text = L"&Open";
			openToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::datafileOpen);
			// 
			// toolStripSeparator
			// 
			toolStripSeparator->Name = L"toolStripSeparator";
			toolStripSeparator->Size = System::Drawing::Size(148, 6);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Enabled = false;
			this->saveToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripMenuItem.Image")));
			this->saveToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->saveToolStripMenuItem->Text = L"&Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::datafileSave);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Enabled = false;
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->saveAsToolStripMenuItem->Text = L"Save &As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::datafileSaveAs);
			// 
			// toolStripSeparator2
			// 
			toolStripSeparator2->Name = L"toolStripSeparator2";
			toolStripSeparator2->Size = System::Drawing::Size(148, 6);
			// 
			// exitToolStripMenuItem
			// 
			exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			exitToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			exitToolStripMenuItem->Text = L"E&xit";
			exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::appExit);
			// 
			// editToolStripMenuItem
			// 
			editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->undoToolStripMenuItem, 
				this->redoToolStripMenuItem, toolStripSeparator3, this->cutToolStripMenuItem, this->copyToolStripMenuItem, this->pasteToolStripMenuItem, 
				toolStripSeparator4, this->selectAllToolStripMenuItem});
			editToolStripMenuItem->Name = L"editToolStripMenuItem";
			editToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			editToolStripMenuItem->Text = L"&Edit";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->undoToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->undoToolStripMenuItem->Text = L"&Undo";
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
			this->redoToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->redoToolStripMenuItem->Text = L"&Redo";
			// 
			// toolStripSeparator3
			// 
			toolStripSeparator3->Name = L"toolStripSeparator3";
			toolStripSeparator3->Size = System::Drawing::Size(147, 6);
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cutToolStripMenuItem.Image")));
			this->cutToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->cutToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->cutToolStripMenuItem->Text = L"Cu&t";
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"copyToolStripMenuItem.Image")));
			this->copyToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copyToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->copyToolStripMenuItem->Text = L"&Copy";
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pasteToolStripMenuItem.Image")));
			this->pasteToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->pasteToolStripMenuItem->Text = L"&Paste";
			// 
			// selectAllToolStripMenuItem
			// 
			this->selectAllToolStripMenuItem->Name = L"selectAllToolStripMenuItem";
			this->selectAllToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->selectAllToolStripMenuItem->Text = L"Select &All";
			// 
			// toolsToolStripMenuItem
			// 
			toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {customizeToolStripMenuItem, 
				optionsToolStripMenuItem});
			toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			toolsToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			toolsToolStripMenuItem->Text = L"&Tools";
			// 
			// customizeToolStripMenuItem
			// 
			customizeToolStripMenuItem->Name = L"customizeToolStripMenuItem";
			customizeToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			customizeToolStripMenuItem->Text = L"&Customize";
			// 
			// optionsToolStripMenuItem
			// 
			optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			optionsToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			optionsToolStripMenuItem->Text = L"&Options";
			// 
			// datafileToolStripMenuItem
			// 
			datafileToolStripMenuItem->Name = L"datafileToolStripMenuItem";
			datafileToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			datafileToolStripMenuItem->Text = L"&Datafile";
			// 
			// toolStripFileNew
			// 
			toolStripFileNew->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			toolStripFileNew->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripFileNew.Image")));
			toolStripFileNew->ImageTransparentColor = System::Drawing::Color::Magenta;
			toolStripFileNew->Name = L"toolStripFileNew";
			toolStripFileNew->Size = System::Drawing::Size(23, 22);
			toolStripFileNew->Text = L"File New";
			toolStripFileNew->Click += gcnew System::EventHandler(this, &FormMain::datafileNew);
			// 
			// toolStripFileOpen
			// 
			toolStripFileOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			toolStripFileOpen->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripFileOpen.Image")));
			toolStripFileOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			toolStripFileOpen->Name = L"toolStripFileOpen";
			toolStripFileOpen->Size = System::Drawing::Size(23, 22);
			toolStripFileOpen->Text = L"File Open";
			toolStripFileOpen->Click += gcnew System::EventHandler(this, &FormMain::datafileOpen);
			// 
			// statusStrip
			// 
			statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {toolStripStatusLabelCWDLabel, 
				this->toolStripStatusLabelCWDValue});
			statusStrip->Location = System::Drawing::Point(0, 426);
			statusStrip->Name = L"statusStrip";
			statusStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::ManagerRenderMode;
			statusStrip->Size = System::Drawing::Size(689, 22);
			statusStrip->TabIndex = 0;
			statusStrip->Text = L"statusStrip";
			// 
			// toolStripStatusLabelCWDValue
			// 
			this->toolStripStatusLabelCWDValue->Name = L"toolStripStatusLabelCWDValue";
			this->toolStripStatusLabelCWDValue->Size = System::Drawing::Size(639, 17);
			this->toolStripStatusLabelCWDValue->Spring = true;
			this->toolStripStatusLabelCWDValue->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// menuStrip
			// 
			menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {fileToolStripMenuItem, editToolStripMenuItem, 
				toolsToolStripMenuItem, helpToolStripMenuItem, datafileToolStripMenuItem});
			menuStrip->Location = System::Drawing::Point(0, 0);
			menuStrip->Name = L"menuStrip";
			menuStrip->Size = System::Drawing::Size(689, 24);
			menuStrip->TabIndex = 1;
			menuStrip->Text = L"menu";
			// 
			// helpToolStripMenuItem
			// 
			helpToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {contentsToolStripMenuItem, 
				indexToolStripMenuItem, searchToolStripMenuItem, this->toolStripSeparator5, aboutToolStripMenuItem});
			helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			helpToolStripMenuItem->Text = L"&Help";
			// 
			// contentsToolStripMenuItem
			// 
			contentsToolStripMenuItem->Name = L"contentsToolStripMenuItem";
			contentsToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			contentsToolStripMenuItem->Text = L"&Contents";
			// 
			// indexToolStripMenuItem
			// 
			indexToolStripMenuItem->Name = L"indexToolStripMenuItem";
			indexToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			indexToolStripMenuItem->Text = L"&Index";
			// 
			// searchToolStripMenuItem
			// 
			searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			searchToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			searchToolStripMenuItem->Text = L"&Search";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(126, 6);
			// 
			// aboutToolStripMenuItem
			// 
			aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			aboutToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			aboutToolStripMenuItem->Text = L"&About...";
			// 
			// toolStrip
			// 
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {toolStripFileNew, toolStripFileOpen, 
				this->toolStripFileSave});
			this->toolStrip->Location = System::Drawing::Point(0, 24);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Size = System::Drawing::Size(689, 25);
			this->toolStrip->TabIndex = 2;
			this->toolStrip->Text = L"toolStrip";
			// 
			// toolStripFileSave
			// 
			this->toolStripFileSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripFileSave->Enabled = false;
			this->toolStripFileSave->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripFileSave.Image")));
			this->toolStripFileSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripFileSave->Name = L"toolStripFileSave";
			this->toolStripFileSave->Size = System::Drawing::Size(23, 22);
			this->toolStripFileSave->Text = L"File Save";
			this->toolStripFileSave->Click += gcnew System::EventHandler(this, &FormMain::datafileSave);
			// 
			// splitter
			// 
			this->splitter->Location = System::Drawing::Point(311, 49);
			this->splitter->MinExtra = 100;
			this->splitter->MinSize = 100;
			this->splitter->Name = L"splitter";
			this->splitter->Size = System::Drawing::Size(3, 377);
			this->splitter->TabIndex = 4;
			this->splitter->TabStop = false;
			this->splitter->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &FormMain::onSplitterMoved);
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"sdf";
			this->openFileDialog->Filter = L"Shadow Datafiles (.sdf)|*.sdf|All files|*.*";
			this->openFileDialog->Title = L"Open Datafile";
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->DefaultExt = L"sdf";
			this->saveFileDialog->Filter = L"Shadow Datafiles (.sdf)|*.sdf|All files|*.*";
			this->saveFileDialog->Title = L"Save Datafile";
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
			// listView
			// 
			this->listView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView->Location = System::Drawing::Point(314, 49);
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(375, 377);
			this->listView->TabIndex = 5;
			this->listView->DatafileChangedCWD += gcnew DatafileGUI::DatafileChangedCWDEventHandler(this, &FormMain::onDatafileChangedCWD);
			this->listView->DatafileChanged += gcnew DatafileGUI::DatafileChangedEventHandler(this, &FormMain::onDatafileChanged);
			// 
			// treeView
			// 
			this->treeView->Dock = System::Windows::Forms::DockStyle::Left;
			this->treeView->Location = System::Drawing::Point(0, 49);
			this->treeView->Margin = System::Windows::Forms::Padding(0);
			this->treeView->Name = L"treeView";
			this->treeView->Size = System::Drawing::Size(311, 377);
			this->treeView->TabIndex = 3;
			this->treeView->DatafileChangedCWD += gcnew DatafileGUI::DatafileChangedCWDEventHandler(this, &FormMain::onDatafileChangedCWD);
			this->treeView->DatafileChanged += gcnew DatafileGUI::DatafileChangedEventHandler(this, &FormMain::onDatafileChanged);
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(689, 448);
			this->Controls->Add(this->listView);
			this->Controls->Add(this->splitter);
			this->Controls->Add(this->treeView);
			this->Controls->Add(this->toolStrip);
			this->Controls->Add(statusStrip);
			this->Controls->Add(menuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = menuStrip;
			this->Name = L"FormMain";
			this->Text = L"Shadow Datafile Manager";
			this->Resize += gcnew System::EventHandler(this, &FormMain::onResize);
			this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
			statusStrip->ResumeLayout(false);
			statusStrip->PerformLayout();
			menuStrip->ResumeLayout(false);
			menuStrip->PerformLayout();
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: float splitValue;
	private: CDatafile* m_pDatafile;
	private: bool m_bDatafileChanged;
	private: CString* m_pDatafilePath;

	private: System::Void appExit(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);
				 Application::Exit();
			 }

	private: System::Void datafileNew(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (m_pDatafile) 
				 { 
					 delete m_pDatafile;
				 }
				 m_pDatafile = new CDatafile(STRING("Untitled.sdf"));

				 treeView->datafileSet(m_pDatafile);
				 listView->datafileSet(m_pDatafile);
				 treeView->update();
				
				 toolStripStatusLabelCWDValue->Text = gcnew String(m_pDatafile->CWD().Value());

				 saveToolStripMenuItem->Enabled = TRUE;
				 saveAsToolStripMenuItem->Enabled = TRUE;
				 toolStripFileSave->Enabled = TRUE;
			 }

	private: System::Void datafileSave(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 if (m_pDatafilePath)
				 {
					 if (m_bDatafileChanged)
					 {
						 m_pDatafile->Write();
						 m_bDatafileChanged = FALSE;
					 }
				 }
				 else
				 {
					 datafileSaveAs(sender, e);
				 }
			 }

	private: System::Void datafileSaveAs(System::Object^  sender, System::EventArgs^  e) {
				  SCF_UNREFERENCED_PARAMETER(e);
				  SCF_UNREFERENCED_PARAMETER(sender);
				  if (saveFileDialog->ShowDialog() ==  System::Windows::Forms::DialogResult::OK)
				  {
					  CString Filename;
					  StringCopy(Filename, saveFileDialog->FileName);

					  CFile File(Filename);

					  m_pDatafile->WriteAs(File);
					  m_bDatafileChanged = FALSE;

					  if (!m_pDatafilePath) { m_pDatafilePath = new CString(); }
					  *m_pDatafilePath = Filename;
				  }
			  }

	private: System::Void datafileOpen(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);
		
				 if (openFileDialog->ShowDialog() ==  System::Windows::Forms::DialogResult::OK)
				 {
					 CString Filename;

					 StringCopy(Filename, openFileDialog->FileName);

					 CFile File(Filename);
					 if (File.Exists())
					 {
						 if (m_pDatafile) { delete m_pDatafile; }

						 m_pDatafile = new CDatafile(Filename);
						 m_pDatafile->Read();
						 m_bDatafileChanged = FALSE;

						 if (!m_pDatafilePath) { m_pDatafilePath = new CString(); }
						 *m_pDatafilePath = Filename;

						 treeView->datafileSet(m_pDatafile);
						 listView->datafileSet(m_pDatafile);
						 treeView->update();
						 
						 toolStripStatusLabelCWDValue->Text = gcnew String(m_pDatafile->CWD().Value());

						 saveToolStripMenuItem->Enabled = TRUE;
						 saveAsToolStripMenuItem->Enabled = TRUE;
						 toolStripFileSave->Enabled = TRUE;
					 }
				 }
			 }
	
	private: System::Void FormMain_Load(System::Object^  sender, System::EventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);
			 }
	private: System::Void onDatafileChangedCWD(Object^ sender, EventArgs^ e) {
				 SCF_UNREFERENCED_PARAMETER(e);

				 toolStripStatusLabelCWDValue->Text = gcnew String(m_pDatafile->CWD().Value());

				 if (sender == treeView) { listView->update(); }
				 if (sender == listView) { treeView->update(); }
			 }
	private: System::Void onDatafileChanged(Object^ sender, EventArgs^ e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 m_bDatafileChanged = TRUE;

				 if (sender == treeView) { listView->update(); }
				 if (sender == listView) { treeView->update(); }
		 }
	private: System::Void onSplitterMoved(System::Object^  sender, System::Windows::Forms::SplitterEventArgs^  e) {
				 SCF_UNREFERENCED_PARAMETER(e);
				 SCF_UNREFERENCED_PARAMETER(sender);

				 splitValue = (float)treeView->Width / (float)this->Width;
			 }
private: System::Void onResize(System::Object^  sender, System::EventArgs^  e) {

			 treeView->Width = (int)(this->Width * splitValue);
		 }
};
}

