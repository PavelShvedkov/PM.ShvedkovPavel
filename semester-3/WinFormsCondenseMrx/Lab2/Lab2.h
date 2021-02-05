#pragma once
#include <iostream>

void matrixRemZero(array<int, 2>^, int*, int*);

namespace Lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Lab2
	/// </summary>
	public ref class Lab2 : public System::Windows::Forms::Form
	{
	public:
		Lab2(void)
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
		~Lab2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveFileToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ loadFileToolStripMenuItem;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;










	protected:



	private: System::ComponentModel::IContainer^ components;

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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->saveFileToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(81, 45);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(51, 22);
			this->textBox3->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(207, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Result";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Matrix";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Rows";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(143, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Columns";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(210, 45);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(55, 22);
			this->textBox2->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(81, 241);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(280, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Condense";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Lab2::Condense);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->saveFileToolStripMenuItem1,
					this->loadFileToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(423, 28);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// saveFileToolStripMenuItem1
			// 
			this->saveFileToolStripMenuItem1->Name = L"saveFileToolStripMenuItem1";
			this->saveFileToolStripMenuItem1->Size = System::Drawing::Size(79, 24);
			this->saveFileToolStripMenuItem1->Text = L"Save file";
			this->saveFileToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Lab2::saveFileToolStripMenuItem1_Click);
			// 
			// loadFileToolStripMenuItem
			// 
			this->loadFileToolStripMenuItem->Name = L"loadFileToolStripMenuItem";
			this->loadFileToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->loadFileToolStripMenuItem->Text = L"Load file";
			this->loadFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Lab2::loadFileToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(47, 24);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Lab2::exitToolStripMenuItem_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(81, 190);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Lab2::clearInput);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(81, 76);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 96);
			this->richTextBox1->TabIndex = 16;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(261, 76);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(100, 96);
			this->richTextBox2->TabIndex = 17;
			this->richTextBox2->Text = L"";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(261, 190);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 23);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Clear";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Lab2::clearOutput);
			// 
			// Lab2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(423, 290);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Lab2";
			this->Text = L"Lab2";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Condense(System::Object^ sender, System::EventArgs^ e) {
		int  i, j, t;
		String^ s = "";

		array<Char>^ ar = gcnew array<Char>(3);
		ar[0] = ' ';
		ar[1] = ';';
		ar[2] = ',';

		array<int, 2>^ matrix;
		int rows = Convert::ToInt32(textBox3->Text);
		int columns = Convert::ToInt32(textBox2->Text);

		if (richTextBox1->Lines->Length == 0)
		{
			MessageBox::Show("Введите матрицу !\n",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			return;
		}

		matrix = gcnew array<int, 2>(rows, columns);

		array<String^>^ as;
		for (i = 0; i < rows; i++)
		{
			as = richTextBox1->Lines[i]->Split(ar);
			for (j = 0; j < columns; j++)
			{
				matrix[i, j] = Convert::ToInt32(as[j]);
			}
		}

		matrixRemZero(matrix, &rows, &columns);

		richTextBox2->Text = "";
		as = gcnew array<String^>(rows);

		for (i = 0; i < rows; i++)
		{
			s = "";
			for (j = 0; j < columns; j++)
			{
				s += matrix[i, j].ToString() + " ";
			}
			as[i] = s;
		}

		richTextBox2->Lines = as;
	}
	private: System::Void clearInput(System::Object^ sender, System::EventArgs^ e)
	{
		richTextBox1->Text = "";
	}
	private: System::Void clearOutput(System::Object^ sender, System::EventArgs^ e)
	{
		richTextBox2->Text = "";
	}
	private: System::Void loadFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::DialogResult dr;
		String^ fn;
		openFileDialog1->FileName = String::Empty;
		// отобразить диалог Открыть
		dr = openFileDialog1->ShowDialog();
		if (dr == System::Windows::Forms::DialogResult::OK)
		{
			fn = openFileDialog1->FileName;
			try
			{
				// считываем данные из файла
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(fn);
				richTextBox1->Text = sr->ReadToEnd();
				sr->Close();
			}
			catch (System::IO::FileLoadException^ e)
			{
				MessageBox::Show("Ошибка ввода:\n", e->Message,
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void saveFileToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::DialogResult dr;
		String^ fn;
		// отобразить диалог Сохранить
		dr = saveFileDialog1->ShowDialog();
		if (dr == System::Windows::Forms::DialogResult::OK)
		{
			fn = saveFileDialog1->FileName;
			// сохранить файл
			try
			{
				// получим информацию о файле fn
				System::IO::FileInfo^ fi =
					gcnew System::IO::FileInfo(fn);
				// поток для записи
				System::IO::StreamWriter^ sw =
					fi->CreateText();
				sw->Write(richTextBox2->Text);
				sw->Close(); // закрываем поток
			}
			catch (System::IO::IOException^ e)
			{
				MessageBox::Show(e->ToString(),
					"Матрицы",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
};


}

void matrixRemZero(array<int, 2>^ mat, int* rows, int* columns) {
	int i, j, k, n = *rows, m = *columns;

	//удаляем нулевые столбцы
	for (j = 0; j < m; ++j)
	{
		i = 0;
		while ((i < n) && (mat[i, j] == 0))
		{
			++i;
		}
		if (i == n)
		{
			break;
		}
	}

	for (i = j; j < *columns; )
	{
		k = 0;
		while ((k < n) && (mat[k, j] == 0))
		{
			++k;
		}
		if (k < n)
		{
			++i;
		}
		else
		{
			--m;
		}

		if (++j >= *columns)
		{
			break;
		}

		for (k = 0; k < n; ++k)
		{
			mat[k, i] = mat[k, j];
		}
	}

	*columns = m;

	//удаляем нулевые строки
	for (i = 0; i < n; ++i)
	{
		j = 0;
		while ((j < m) && (mat[i, j] == 0))
		{
			++j;
		}
		if (j == m)
		{
			break;
		}
	}

	for (j = i; j < *rows; ) {
		k = 0;
		while ((k < m) && (mat[j, k] == 0))
		{
			++k;
		}

		if (k < m)
		{
			++i;
		}
		else
		{
			--n;
		}

		if (++j >= *rows)
		{
			break;
		}

		for (k = 0; k < m; ++k)
		{
			mat[i, k] = mat[j, k];
		}
	}

	*rows = n;
}