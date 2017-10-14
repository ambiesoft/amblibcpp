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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 137);
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
};
}

