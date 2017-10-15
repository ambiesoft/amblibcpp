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
	/// Form1 の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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


	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
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
			this->SuspendLayout();
			// 
			// btnWithNullptr
			// 
			this->btnWithNullptr->Location = System::Drawing::Point(0, 0);
			this->btnWithNullptr->Name = L"btnWithNullptr";
			this->btnWithNullptr->Size = System::Drawing::Size(75, 25);
			this->btnWithNullptr->TabIndex = 0;
			this->btnWithNullptr->Text = L"with nullptr";
			this->btnWithNullptr->UseVisualStyleBackColor = true;
			this->btnWithNullptr->Click += gcnew System::EventHandler(this, &Form1::btnWithNullptr_Click);
			// 
			// btnWithActiveForm
			// 
			this->btnWithActiveForm->Location = System::Drawing::Point(0, 31);
			this->btnWithActiveForm->Name = L"btnWithActiveForm";
			this->btnWithActiveForm->Size = System::Drawing::Size(75, 25);
			this->btnWithActiveForm->TabIndex = 1;
			this->btnWithActiveForm->Text = L"with ActiveForm";
			this->btnWithActiveForm->UseVisualStyleBackColor = true;
			this->btnWithActiveForm->Click += gcnew System::EventHandler(this, &Form1::btnWithActiveForm_Click);
			// 
			// btnWithThis
			// 
			this->btnWithThis->Location = System::Drawing::Point(0, 63);
			this->btnWithThis->Name = L"btnWithThis";
			this->btnWithThis->Size = System::Drawing::Size(75, 25);
			this->btnWithThis->TabIndex = 2;
			this->btnWithThis->Text = L"with this";
			this->btnWithThis->UseVisualStyleBackColor = true;
			this->btnWithThis->Click += gcnew System::EventHandler(this, &Form1::btnWithThis_Click);
			// 
			// btnFolderNormal
			// 
			this->btnFolderNormal->Location = System::Drawing::Point(91, 0);
			this->btnFolderNormal->Name = L"btnFolderNormal";
			this->btnFolderNormal->Size = System::Drawing::Size(123, 25);
			this->btnFolderNormal->TabIndex = 3;
			this->btnFolderNormal->Text = L"folder normal";
			this->btnFolderNormal->UseVisualStyleBackColor = true;
			this->btnFolderNormal->Click += gcnew System::EventHandler(this, &Form1::btnFolder_Click);
			// 
			// btnFolderCentering
			// 
			this->btnFolderCentering->Location = System::Drawing::Point(91, 31);
			this->btnFolderCentering->Name = L"btnFolderCentering";
			this->btnFolderCentering->Size = System::Drawing::Size(123, 25);
			this->btnFolderCentering->TabIndex = 4;
			this->btnFolderCentering->Text = L"folder centering";
			this->btnFolderCentering->UseVisualStyleBackColor = true;
			this->btnFolderCentering->Click += gcnew System::EventHandler(this, &Form1::btnFolderCentering_Click);
			// 
			// btnlsMiscFolder
			// 
			this->btnlsMiscFolder->Location = System::Drawing::Point(91, 63);
			this->btnlsMiscFolder->Name = L"btnlsMiscFolder";
			this->btnlsMiscFolder->Size = System::Drawing::Size(123, 25);
			this->btnlsMiscFolder->TabIndex = 5;
			this->btnlsMiscFolder->Text = L"folder lsMisc";
			this->btnlsMiscFolder->UseVisualStyleBackColor = true;
			this->btnlsMiscFolder->Click += gcnew System::EventHandler(this, &Form1::btnlsMiscFolder_Click);
			// 
			// btnColorCentering
			// 
			this->btnColorCentering->Location = System::Drawing::Point(91, 123);
			this->btnColorCentering->Name = L"btnColorCentering";
			this->btnColorCentering->Size = System::Drawing::Size(123, 23);
			this->btnColorCentering->TabIndex = 6;
			this->btnColorCentering->Text = L"&color Centering";
			this->btnColorCentering->UseVisualStyleBackColor = true;
			this->btnColorCentering->Click += gcnew System::EventHandler(this, &Form1::btnColorCentering_Click);
			// 
			// btnOtherTest
			// 
			this->btnOtherTest->Location = System::Drawing::Point(0, 197);
			this->btnOtherTest->Name = L"btnOtherTest";
			this->btnOtherTest->Size = System::Drawing::Size(75, 23);
			this->btnOtherTest->TabIndex = 7;
			this->btnOtherTest->Text = L"&OtherTest";
			this->btnOtherTest->UseVisualStyleBackColor = true;
			this->btnOtherTest->Click += gcnew System::EventHandler(this, &Form1::btnOtherTest_Click);
			// 
			// btnColorNormal
			// 
			this->btnColorNormal->Location = System::Drawing::Point(91, 94);
			this->btnColorNormal->Name = L"btnColorNormal";
			this->btnColorNormal->Size = System::Drawing::Size(123, 23);
			this->btnColorNormal->TabIndex = 6;
			this->btnColorNormal->Text = L"&color Normal";
			this->btnColorNormal->UseVisualStyleBackColor = true;
			this->btnColorNormal->Click += gcnew System::EventHandler(this, &Form1::btnColorNormal_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 328);
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

		Ambiesoft::CppUtils::CopyFile(L"Y:\\T\\*.zip", L"Y:\\T\\aaa\\");
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
	};
}

