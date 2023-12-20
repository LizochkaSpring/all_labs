#pragma once
#include"../queuelib/Queue.h"
namespace Gpafqueue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int MaxSize;
		int Size;
		double p;
		double q;
		int PopCount;
		int PushCount;
		
		MyQueue<int>*pQueue;
		
		int CenterX, CenterY, Width, Heidht;
		Random^ rnd1;
		Graphics^ gr;
		Pen^ BlackPen;
		Pen^ WhitePen;
	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
		   bool Flag;

		MyForm()
		{
			InitializeComponent();
			gr = CreateGraphics();
			rnd1 = gcnew Random();
			BlackPen = gcnew Pen(Color::DeepPink);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.0F;
			CenterX = 150;
			CenterY = 200;
			Width = Heidht = 200;
			PopCount = PushCount = 0;
			Flag = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button2;
	private: System::ComponentModel::IContainer^ components;
	
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(364, 74);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 42);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(364, 157);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 43);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(208, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Максимальная длина очереди ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Исходная длина очереди";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(39, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(173, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Вероятность добавления";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(38, 161);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(173, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Вероятность извлечения";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(62, 205);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(149, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Добавлено в очередь";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(52, 246);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(159, 16);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Извлечено из очереди";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(218, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(218, 74);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(218, 114);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 10;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(218, 157);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 11;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(218, 202);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 12;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(218, 245);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 382);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	void DrawQueue() {
		//Вычисляем стартовый угол
		int start = 360 * pQueue->GetFirst() / pQueue->GetMaxSize();
		int finish = 360 * pQueue->GetSize() / pQueue->GetMaxSize();
		//нарисовать дугу от tail до head
		gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
	}
	void Clean() {
		//Вычисляем стартовый угол
		int start = 360 * pQueue->GetFirst() / pQueue->GetMaxSize();
		int finish = 360 * pQueue->GetSize() / pQueue->GetMaxSize();
		//нарисовать дугу цветом фона от tail до head
		gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, start, finish);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (!Flag) {
			try {
				MaxSize = System::Convert::ToInt32(textBox1->Text);
				Size = System::Convert::ToInt32(textBox2->Text);
				pQueue = new MyQueue<int>(MaxSize);
				for (int i = 0; i < Size; ++i)
					pQueue->Push(1);
				p = System::Convert::ToDouble(textBox3->Text);
				q = System::Convert::ToDouble(textBox4->Text);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

			Flag = true;
			timer1->Enabled = true;
		}
		else
		{
			MessageBox::Show("!");
			return;
		}
		//Graphics^ gr = this -> CreateGraphics();
		////gr->DrawLine(Pens::Black, 10,10,100,200);
		//Pen^ BlackPen = gcnew Pen(Color::DeepPink);
		//BlackPen->Width = 10.0F;
		//gr->DrawArc(BlackPen,10,10,200,200,0,90);
		//timer1->Enabled = true;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Стереть очередь
		Clean();
		try {
			//Обновить состояние очереди
			if (rnd1->NextDouble() < p) {
				pQueue->Push(1);
				PushCount++;
			}
			if (rnd1->NextDouble() < q) {
				pQueue->Pop();
				PopCount++;
			}
		}
		catch (Exception^ ex) {

		}
		//Нарисовать очередь 
		DrawQueue();
		//Обновить статистику
		textBox5->Text = Convert::ToString(PushCount);
		textBox6->Text = Convert::ToString(PopCount);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		Clean();

		PushCount = 0;
		PopCount = 0;

		textBox5->Text = "";
		textBox6->Text = "";

		this->Refresh();
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
