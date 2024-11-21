#pragma once


namespace AmbLibcppTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Ambiesoft;

	/// <summary>
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			DVERIFY(CppUtils::MakeRichEditFontPersist(richText));
		}

	protected:
		/// <summary>
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnWithNullptr;
	protected:
	private: System::Windows::Forms::Button^  btnWithActiveForm;
	private: System::Windows::Forms::Button^  btnWithThis;
	private: System::Windows::Forms::Button^  btnFolderNormal;
	private: System::Windows::Forms::Button^  btnFolderCentering;
	private: System::Windows::Forms::Button^  btnlsMiscFolder;
	private: System::Windows::Forms::Button^  btnColorCentering;

	private: System::Windows::Forms::Button^  btnOtherTest;
	private: System::Windows::Forms::Button^  btnColorNormal;
	private: System::Windows::Forms::Button^  btnCreateDesktopShortcut;
	private: System::Windows::Forms::Button^  btnNazo;
	private: System::Windows::Forms::RichTextBox^ richText;



	private:
		/// <summary>
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnWithNullptr = (gcnew System::Windows::Forms::Button());
			this->btnWithActiveForm = (gcnew System::Windows::Forms::Button());
			this->btnWithThis = (gcnew System::Windows::Forms::Button());
			this->btnFolderNormal = (gcnew System::Windows::Forms::Button());
			this->btnFolderCentering = (gcnew System::Windows::Forms::Button());
			this->btnlsMiscFolder = (gcnew System::Windows::Forms::Button());
			this->btnColorCentering = (gcnew System::Windows::Forms::Button());
			this->btnOtherTest = (gcnew System::Windows::Forms::Button());
			this->btnColorNormal = (gcnew System::Windows::Forms::Button());
			this->btnCreateDesktopShortcut = (gcnew System::Windows::Forms::Button());
			this->btnNazo = (gcnew System::Windows::Forms::Button());
			this->richText = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// btnWithNullptr
			// 
			this->btnWithNullptr->Location = System::Drawing::Point(0, 0);
			this->btnWithNullptr->Name = L"btnWithNullptr";
			this->btnWithNullptr->Size = System::Drawing::Size(75, 23);
			this->btnWithNullptr->TabIndex = 0;
			this->btnWithNullptr->Text = L"with nullptr";
			this->btnWithNullptr->UseVisualStyleBackColor = true;
			this->btnWithNullptr->Click += gcnew System::EventHandler(this, &Form1::btnWithNullptr_Click);
			// 
			// btnWithActiveForm
			// 
			this->btnWithActiveForm->Location = System::Drawing::Point(0, 29);
			this->btnWithActiveForm->Name = L"btnWithActiveForm";
			this->btnWithActiveForm->Size = System::Drawing::Size(75, 23);
			this->btnWithActiveForm->TabIndex = 1;
			this->btnWithActiveForm->Text = L"with ActiveForm";
			this->btnWithActiveForm->UseVisualStyleBackColor = true;
			this->btnWithActiveForm->Click += gcnew System::EventHandler(this, &Form1::btnWithActiveForm_Click);
			// 
			// btnWithThis
			// 
			this->btnWithThis->Location = System::Drawing::Point(0, 58);
			this->btnWithThis->Name = L"btnWithThis";
			this->btnWithThis->Size = System::Drawing::Size(75, 23);
			this->btnWithThis->TabIndex = 2;
			this->btnWithThis->Text = L"with this";
			this->btnWithThis->UseVisualStyleBackColor = true;
			this->btnWithThis->Click += gcnew System::EventHandler(this, &Form1::btnWithThis_Click);
			// 
			// btnFolderNormal
			// 
			this->btnFolderNormal->Location = System::Drawing::Point(91, 0);
			this->btnFolderNormal->Name = L"btnFolderNormal";
			this->btnFolderNormal->Size = System::Drawing::Size(123, 23);
			this->btnFolderNormal->TabIndex = 3;
			this->btnFolderNormal->Text = L"folder normal";
			this->btnFolderNormal->UseVisualStyleBackColor = true;
			this->btnFolderNormal->Click += gcnew System::EventHandler(this, &Form1::btnFolder_Click);
			// 
			// btnFolderCentering
			// 
			this->btnFolderCentering->Location = System::Drawing::Point(91, 29);
			this->btnFolderCentering->Name = L"btnFolderCentering";
			this->btnFolderCentering->Size = System::Drawing::Size(123, 23);
			this->btnFolderCentering->TabIndex = 4;
			this->btnFolderCentering->Text = L"folder centering";
			this->btnFolderCentering->UseVisualStyleBackColor = true;
			this->btnFolderCentering->Click += gcnew System::EventHandler(this, &Form1::btnFolderCentering_Click);
			// 
			// btnlsMiscFolder
			// 
			this->btnlsMiscFolder->Location = System::Drawing::Point(91, 58);
			this->btnlsMiscFolder->Name = L"btnlsMiscFolder";
			this->btnlsMiscFolder->Size = System::Drawing::Size(123, 23);
			this->btnlsMiscFolder->TabIndex = 5;
			this->btnlsMiscFolder->Text = L"folder lsMisc";
			this->btnlsMiscFolder->UseVisualStyleBackColor = true;
			this->btnlsMiscFolder->Click += gcnew System::EventHandler(this, &Form1::btnlsMiscFolder_Click);
			// 
			// btnColorCentering
			// 
			this->btnColorCentering->Location = System::Drawing::Point(91, 114);
			this->btnColorCentering->Name = L"btnColorCentering";
			this->btnColorCentering->Size = System::Drawing::Size(123, 21);
			this->btnColorCentering->TabIndex = 6;
			this->btnColorCentering->Text = L"&color Centering";
			this->btnColorCentering->UseVisualStyleBackColor = true;
			this->btnColorCentering->Click += gcnew System::EventHandler(this, &Form1::btnColorCentering_Click);
			// 
			// btnOtherTest
			// 
			this->btnOtherTest->Location = System::Drawing::Point(0, 182);
			this->btnOtherTest->Name = L"btnOtherTest";
			this->btnOtherTest->Size = System::Drawing::Size(75, 21);
			this->btnOtherTest->TabIndex = 7;
			this->btnOtherTest->Text = L"&OtherTest";
			this->btnOtherTest->UseVisualStyleBackColor = true;
			this->btnOtherTest->Click += gcnew System::EventHandler(this, &Form1::btnOtherTest_Click);
			// 
			// btnColorNormal
			// 
			this->btnColorNormal->Location = System::Drawing::Point(91, 87);
			this->btnColorNormal->Name = L"btnColorNormal";
			this->btnColorNormal->Size = System::Drawing::Size(123, 21);
			this->btnColorNormal->TabIndex = 6;
			this->btnColorNormal->Text = L"&color Normal";
			this->btnColorNormal->UseVisualStyleBackColor = true;
			this->btnColorNormal->Click += gcnew System::EventHandler(this, &Form1::btnColorNormal_Click);
			// 
			// btnCreateDesktopShortcut
			// 
			this->btnCreateDesktopShortcut->Location = System::Drawing::Point(229, 0);
			this->btnCreateDesktopShortcut->Name = L"btnCreateDesktopShortcut";
			this->btnCreateDesktopShortcut->Size = System::Drawing::Size(135, 21);
			this->btnCreateDesktopShortcut->TabIndex = 8;
			this->btnCreateDesktopShortcut->Text = L"CreateDesktopShortcut";
			this->btnCreateDesktopShortcut->UseVisualStyleBackColor = true;
			this->btnCreateDesktopShortcut->Click += gcnew System::EventHandler(this, &Form1::btnCreateDesktopShortcut_Click);
			// 
			// btnNazo
			// 
			this->btnNazo->Location = System::Drawing::Point(91, 182);
			this->btnNazo->Name = L"btnNazo";
			this->btnNazo->Size = System::Drawing::Size(75, 21);
			this->btnNazo->TabIndex = 9;
			this->btnNazo->Text = L"Nazo";
			this->btnNazo->UseVisualStyleBackColor = true;
			this->btnNazo->Click += gcnew System::EventHandler(this, &Form1::btnNazo_Click);
			// 
			// richText
			// 
			this->richText->Location = System::Drawing::Point(327, 88);
			this->richText->Name = L"richText";
			this->richText->Size = System::Drawing::Size(167, 96);
			this->richText->TabIndex = 10;
			this->richText->Text = L"I am rich";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 303);
			this->Controls->Add(this->richText);
			this->Controls->Add(this->btnNazo);
			this->Controls->Add(this->btnCreateDesktopShortcut);
			this->Controls->Add(this->btnOtherTest);
			this->Controls->Add(this->btnColorNormal);
			this->Controls->Add(this->btnColorCentering);
			this->Controls->Add(this->btnlsMiscFolder);
			this->Controls->Add(this->btnFolderCentering);
			this->Controls->Add(this->btnFolderNormal);
			this->Controls->Add(this->btnWithThis);
			this->Controls->Add(this->btnWithActiveForm);
			this->Controls->Add(this->btnWithNullptr);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		Ambiesoft::CppUtils::moveWindowSpecific(this, Ambiesoft::CPPUTIL_MOVEWINDOWTYPE::BOTTOMLEFT);
		DVERIFY(CppUtils::MakeRichEditFontPersist(richText));
	}
	private: System::Void btnWithNullptr_Click(System::Object^  sender, System::EventArgs^  e) {
		CppUtils::CenteredMessageBox("nullptr");
	}
	private: System::Void btnWithActiveForm_Click(System::Object^  sender, System::EventArgs^  e) {
		CppUtils::CenteredMessageBox(Form::ActiveForm, "ActiveForm");
	}
	private: System::Void btnWithThis_Click(System::Object^  sender, System::EventArgs^  e) {
		CppUtils::CenteredMessageBox(this, "this");
	}


	private: System::Void btnFolder_Click(System::Object^  sender, System::EventArgs^  e) {
		FolderBrowserDialog fbd;
		fbd.ShowDialog(this);
	}
	private: System::Void btnFolderCentering_Click(System::Object^  sender, System::EventArgs^  e) {
		CenteringDialog centering(this);
		FolderBrowserDialog fbd;
		fbd.ShowDialog(this);
	}


	private: System::Void btnlsMiscFolder_Click(System::Object^  sender, System::EventArgs^  e) {
		CenteringDialog centering(this);
		String^ folder;
		browseFolder(this, "title", folder);
	}
	private: System::Void btnOtherTest_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ mime = Ambiesoft::CppUtils::getMimeTypeFromExtention(".txt");
		mime = Ambiesoft::CppUtils::getMimeTypeFromExtention(".ini");
		mime = Ambiesoft::CppUtils::getMimeTypeFromExtention(".cpp");
		{
			array<unsigned char>^ zaa;
			if (Ambiesoft::CppUtils::ReadAlternate(L"C:\\T\\magic", L"alt", zaa))
			{
				String^ ttt = System::Text::Encoding::UTF8->GetString(zaa);
			}

		}
		String^ aaa = "aaa";
		array<unsigned char>^ baaa = System::Text::Encoding::UTF8->GetBytes(aaa);

		System::Diagnostics::Debug::Assert(
			Ambiesoft::CppUtils::WriteAlternate(L"C:\\T\\magic", L"alt", baaa)
			);

		array<unsigned char>^ zaa;
		System::Diagnostics::Debug::Assert(
			Ambiesoft::CppUtils::ReadAlternate(L"C:\\T\\magic", L"alt", zaa)
			);

		String^ zzz = System::Text::Encoding::UTF8->GetString(zaa);
		System::Diagnostics::Debug::Assert(baaa->Length == zaa->Length);
		System::Diagnostics::Debug::Assert(aaa == zzz);

		array<String^>^ as = gcnew array<String^>(2);
		as[0] = L"C:\\T\\x\\a";
		as[1] = L"C:\\T\\x\\b";
		Ambiesoft::CppUtils::DeleteFiles(as);
		Ambiesoft::CppUtils::DeleteFile(L"C:\\T\\x\\*.csproj");

		InvisibleForm invf(L"Y:\\T\\*.zip", L"Y:\\T\\aaa\\");
		invf.ShowDialog();
		// Ambiesoft::CppUtils::CopyFile(this, L"Y:\\T\\*.zip", L"Y:\\T\\aaa\\");
	}
	private: System::Void btnColorNormal_Click(System::Object^  sender, System::EventArgs^  e) {
		ColorDialog dlg;
		dlg.ShowDialog();
	}
	private: System::Void btnColorCentering_Click(System::Object^  sender, System::EventArgs^  e) {
		CenteringDialog centering(this);
		ColorDialog dlg;
		dlg.ShowDialog();
	}
	private: System::Void btnCreateDesktopShortcut_Click(System::Object^  sender, System::EventArgs^  e) {
		CppUtils::CreateDesktopShortcut(this, "myshortcut file", Application::ExecutablePath);
	}
	private: System::Void btnNazo_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ ver = CppUtils::GetNativeVersionString(Application::ExecutablePath, 3);
		{
			CenteringDialog center(nullptr);
		}
		CppUtils::CenteredMessageBox(ver);
	}
};
}

