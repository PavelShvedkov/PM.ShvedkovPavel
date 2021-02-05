#pragma once
#include <iostream>

typedef int(*Comparator)(int, int);
void bubleSort(int*, int, Comparator);
void insertSort(int*, int,Comparator);
void selectionSort(int*, int, Comparator);
void quickSort(int*, int, int, Comparator);
int increase(int, int);
int decrease(int, int);

namespace Project1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox1;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(137, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(46, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(137, 40);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(325, 22);
			this->textBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Array size";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Elements of array";
			// 
			// comboBox1
			// 
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Buble sort", L"Insert sort", L"Selection sort",
					L"Quick sort"
			});
			this->comboBox1->Location = System::Drawing::Point(137, 68);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(160, 24);
			this->comboBox1->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(61, 108);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(339, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Sort";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::startSorting);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Type of sort";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Enabled = false;
			this->label4->Location = System::Drawing::Point(197, 236);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 17);
			this->label4->TabIndex = 7;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(371, 70);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(91, 21);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Decrease";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->ClientSize = System::Drawing::Size(474, 420);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Sorting an array";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void startSorting(System::Object^ sender, System::EventArgs^ e)
	{
		String^ numbersInStr = System::Convert::ToString(textBox2->Text);;
		array<Char>^ separators = gcnew array<Char>(3);
		separators[0] = ' ';
		separators[1] = ',';
		separators[2] = ';';

		array<String^>^ arrStrings = numbersInStr->Split(separators);
		int length = System::Convert::ToInt16(textBox1->Text);
		int* array = new int[length];

		for (int i = 0; i < length; i++)
		{
			array[i] = System::Convert::ToInt32(arrStrings[i]);
		}

		int variant = System::Convert::ToInt16(comboBox1->SelectedIndex);
		Comparator comparator = increase;

		if (checkBox1->Checked)
		{
			comparator = decrease;
		} 

		switch (variant)
		{
		case 0:
			bubleSort(array, length,comparator);
			break;
		case 1:
			insertSort(array, length, comparator);
			break;
		case 2:
			selectionSort(array, length, comparator);
			break;
		case 3:
			quickSort(array, 0, length - 1, comparator);
			break;
		default:
			label4->Text = "Choose another sorting option: this one doesn't work";
			return;
		}

		String^ result;

		for (int i = 0; i < length; i++)
		{
			result += System::Convert::ToString(array[i]) + " ";
		}

		label4->Text = result;
	}
	};
}

void bubleSort(int* sourceArray, int n,Comparator comparator)
{
	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;
		for (int j = n - 1; j > i; j--)
		{
			if (comparator(sourceArray[j], sourceArray[j - 1])>0)
			{
				std::swap(sourceArray[j], sourceArray[j - 1]);
				isSorted = false;
			}
		}
		i++;
	}
}
void insertSort(int* sourceArray, int n, Comparator comparator)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && comparator(sourceArray[j - 1], sourceArray[j])<0; j--)
		{
			std::swap(sourceArray[j - 1], sourceArray[j]);
		}
	}
}
void selectionSort(int* sourceArray, int n, Comparator comparator)
{
	for (int* unsortedEl = sourceArray, *currentMin = sourceArray, i = 0; unsortedEl < sourceArray + n; i++, unsortedEl++, currentMin = unsortedEl)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (*currentMin == *(unsortedEl + j))
			{
				continue;
			}
			if (comparator(*currentMin , * (unsortedEl + j))<0)
			{
				std::swap(*currentMin, *(unsortedEl + j));
				continue;
			}
			std::swap(*currentMin, *unsortedEl);
		}

	}
}
void quickSort(int* array, int left, int right, Comparator comparator)
{
	int pivot;
	int lHold = left;
	int rHold = right;
	pivot = array[left];
	while (left < right)
	{
		while ((comparator(array[right],pivot)>=0) && (left < right))
			right--;
		if (left != right)
		{
			array[left] = array[right];
			left++;
		}
		while ((comparator(array[left], pivot) <= 0) && (left < right))
			left++;
		if (left != right)
		{
			array[right] = array[left];
			right--;
		}
	}
	array[left] = pivot;
	pivot = left;
	left = lHold;
	right = rHold;
	if (left < pivot)
		quickSort(array, left, pivot - 1,comparator);
	if (right > pivot)
		quickSort(array, pivot + 1, right,comparator);
}

int increase(int lho, int rho)
{
	return  rho - lho;
}
int decrease(int lho, int rho)
{
	return  lho - rho;
}