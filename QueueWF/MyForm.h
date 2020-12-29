#pragma once

#include "../Queue/Queue.h"

namespace QueueWF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int MaxSize, Size;
		double p, q;
		int PopCount, PushCount;
		TQueue<int>* queue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rndl;
		Pen^ BlackPen;
	private: System::Windows::Forms::Button^ button3;
	//private: System::Windows::Forms::Timer^ timer1;
		   Pen^ WhitePen;
	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			rndl = gcnew Random();
			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.5F;
			CenterX = 220;
			CenterY = 300;
			Width = Height = 200;
			PopCount = PushCount = 0;
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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	//private: System::Windows::Forms::Button^ button3;
	private: System::ComponentModel::IContainer^ components;
	

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(20, 20);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Максимальный размер очереди\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Location = System::Drawing::Point(20, 55);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(172, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Стартовый размер очереди\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Location = System::Drawing::Point(20, 92);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(212, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Вероятность включения элемента";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label4->Location = System::Drawing::Point(20, 130);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(218, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Вероятность исключения элемента";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(298, 12);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(168, 21);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(298, 126);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(168, 21);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(298, 88);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(168, 21);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(298, 51);
			this->textBox4->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(168, 21);
			this->textBox4->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Window;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::DarkOrange;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkOrange;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DarkOrange;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(539, 55);
			this->button1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 27);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::DarkOrange;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkOrange;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DarkOrange;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(539, 158);
			this->button2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 27);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(20, 210);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(139, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Извлечено из очереди";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label6->Location = System::Drawing::Point(20, 168);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(135, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Добавлено в очередь";
			// 
			// textBox5
			// 
			this->textBox5->Cursor = System::Windows::Forms::Cursors::No;
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(298, 206);
			this->textBox5->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(168, 21);
			this->textBox5->TabIndex = 12;
			// 
			// textBox6
			// 
			this->textBox6->Cursor = System::Windows::Forms::Cursors::No;
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(298, 164);
			this->textBox6->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(168, 21);
			this->textBox6->TabIndex = 13;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::DarkOrange;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkOrange;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DarkOrange;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->Location = System::Drawing::Point(539, 109);
			this->button3->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(116, 27);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Продолжить";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 400;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(712, 532);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Queue";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox4->Text);
		p = Convert::ToDouble(textBox3->Text, gcnew CultureInfo("en-US"));
		q = Convert::ToDouble(textBox2->Text, gcnew CultureInfo("en-US"));
		queue = new TQueue<int>(MaxSize);
		PushCount = 0;
		PopCount = 0;
		for (int i = 0; i < Size; i++)
			queue->Push(i);
		DrawQueue();
		timer1->Enabled = true;
	}
		   void DrawQueue()
		   {
			   int start = 360 * queue->GetNumberHead() / queue->GetMaxSize();
			   int finish = 360 * queue->GetSize() / queue->GetMaxSize();
			   gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
		   }
		   void Clean()
		   {
			   gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, 0, 360);
		   }
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	Clean();
	if (rndl->NextDouble() < p)
	{
		if (Size < MaxSize)
		{
			queue->Push(1);
			Size++;
			PushCount++;
		}
	}
	if (rndl->NextDouble() < q)
	{
		if (Size > 0)
		{
			queue->GetHead();
			Size--;
			PopCount++;
		}
	}
	DrawQueue();
	textBox6->Text = Convert::ToString(PushCount);
	textBox5->Text = Convert::ToString(PopCount);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	p = Convert::ToDouble(textBox3->Text);
	q = Convert::ToDouble(textBox2->Text);
	timer1->Enabled = true;
}
};
}
