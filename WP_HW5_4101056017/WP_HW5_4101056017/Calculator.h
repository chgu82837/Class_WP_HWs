/***************************
4101056017 邱冠喻 第五次作業 12/10
4101056017 Chiu Guan-Yu TheFifthHomework 12/10
***************************/

#pragma once

namespace WP_HW5_4101056017 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Calculator 的摘要
	/// </summary>
	public ref class Calculator : public System::Windows::Forms::Form
	{
	public:
		Calculator(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			renew();
			memory = 0.0;
		}

		Double^ memory;

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Calculator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  exit;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  cnt;
	private: System::Windows::Forms::Button^  prev;

	private: System::Windows::Forms::Button^  next;
	private: System::Windows::Forms::Label^  output;
	private: System::Windows::Forms::ListBox^  dataset;






	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  add;

	private: System::Windows::Forms::Button^  inv;
	private: System::Windows::Forms::Button^  dot;
	private: System::Windows::Forms::Button^  zero2;
	private: System::Windows::Forms::Button^  zero;




	private: System::Windows::Forms::Button^  pdev;

	private: System::Windows::Forms::Button^  dev;
	private: System::Windows::Forms::Button^  button3;


	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  sum2;

	private: System::Windows::Forms::Button^  sum;
	private: System::Windows::Forms::Button^  button6;


	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::Button^  ave2;

	private: System::Windows::Forms::Button^  ave;
	private: System::Windows::Forms::Button^  button9;


	private: System::Windows::Forms::Button^  button8;

	private: System::Windows::Forms::Button^  button7;


	private: System::Windows::Forms::Button^  exp;

	private: System::Windows::Forms::Button^  f_e;

	private: System::Windows::Forms::Button^  clear;

	private: System::Windows::Forms::Button^  cad;

	private: System::Windows::Forms::Button^  bs;

	private: System::Windows::Forms::Button^  mm;

	private: System::Windows::Forms::Button^  mp;

	private: System::Windows::Forms::Button^  ms;

	private: System::Windows::Forms::Button^  mr;

	private: System::Windows::Forms::Button^  mc;

	private: System::Windows::Forms::ToolStripMenuItem^  about;














	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->about = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->cnt = (gcnew System::Windows::Forms::Label());
			this->prev = (gcnew System::Windows::Forms::Button());
			this->next = (gcnew System::Windows::Forms::Button());
			this->output = (gcnew System::Windows::Forms::Label());
			this->dataset = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->add = (gcnew System::Windows::Forms::Button());
			this->inv = (gcnew System::Windows::Forms::Button());
			this->dot = (gcnew System::Windows::Forms::Button());
			this->zero2 = (gcnew System::Windows::Forms::Button());
			this->zero = (gcnew System::Windows::Forms::Button());
			this->pdev = (gcnew System::Windows::Forms::Button());
			this->dev = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->sum2 = (gcnew System::Windows::Forms::Button());
			this->sum = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->ave2 = (gcnew System::Windows::Forms::Button());
			this->ave = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->exp = (gcnew System::Windows::Forms::Button());
			this->f_e = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->cad = (gcnew System::Windows::Forms::Button());
			this->bs = (gcnew System::Windows::Forms::Button());
			this->mm = (gcnew System::Windows::Forms::Button());
			this->mp = (gcnew System::Windows::Forms::Button());
			this->ms = (gcnew System::Windows::Forms::Button());
			this->mr = (gcnew System::Windows::Forms::Button());
			this->mc = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItem1});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(365, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->about, 
				this->exit});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(49, 20);
			this->toolStripMenuItem1->Text = L"★☆★";
			// 
			// about
			// 
			this->about->Name = L"about";
			this->about->Size = System::Drawing::Size(100, 22);
			this->about->Text = L"說明";
			this->about->Click += gcnew System::EventHandler(this, &Calculator::about_Click);
			// 
			// exit
			// 
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(100, 22);
			this->exit->Text = L"離開";
			this->exit->Click += gcnew System::EventHandler(this, &Calculator::Exit_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(365, 509);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->output, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->dataset, 0, 2);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->Size = System::Drawing::Size(359, 197);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				60)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->tableLayoutPanel3->Controls->Add(this->cnt, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->prev, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->next, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(353, 24);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// cnt
			// 
			this->cnt->AutoSize = true;
			this->cnt->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cnt->Location = System::Drawing::Point(3, 0);
			this->cnt->Name = L"cnt";
			this->cnt->Size = System::Drawing::Size(205, 24);
			this->cnt->TabIndex = 0;
			this->cnt->Text = L"Count = 0";
			this->cnt->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// prev
			// 
			this->prev->Dock = System::Windows::Forms::DockStyle::Fill;
			this->prev->Location = System::Drawing::Point(214, 3);
			this->prev->Name = L"prev";
			this->prev->Size = System::Drawing::Size(64, 18);
			this->prev->TabIndex = 1;
			this->prev->Text = L"↑";
			this->prev->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->prev->UseVisualStyleBackColor = true;
			this->prev->Click += gcnew System::EventHandler(this, &Calculator::prev_Click);
			// 
			// next
			// 
			this->next->Dock = System::Windows::Forms::DockStyle::Fill;
			this->next->Location = System::Drawing::Point(284, 3);
			this->next->Name = L"next";
			this->next->Size = System::Drawing::Size(66, 18);
			this->next->TabIndex = 2;
			this->next->Text = L"↓";
			this->next->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->next->UseVisualStyleBackColor = true;
			this->next->Click += gcnew System::EventHandler(this, &Calculator::next_Click);
			// 
			// output
			// 
			this->output->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->output->AutoSize = true;
			this->output->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->output->Location = System::Drawing::Point(3, 30);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(353, 29);
			this->output->TabIndex = 1;
			this->output->Text = L"0";
			this->output->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// dataset
			// 
			this->dataset->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataset->FormattingEnabled = true;
			this->dataset->Location = System::Drawing::Point(3, 68);
			this->dataset->Name = L"dataset";
			this->dataset->Size = System::Drawing::Size(353, 126);
			this->dataset->TabIndex = 2;
			this->dataset->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Calculator::dataset_MouseDoubleClick);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 5;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->tableLayoutPanel4->Controls->Add(this->add, 4, 5);
			this->tableLayoutPanel4->Controls->Add(this->inv, 3, 5);
			this->tableLayoutPanel4->Controls->Add(this->dot, 2, 5);
			this->tableLayoutPanel4->Controls->Add(this->zero2, 1, 5);
			this->tableLayoutPanel4->Controls->Add(this->zero, 0, 5);
			this->tableLayoutPanel4->Controls->Add(this->pdev, 4, 4);
			this->tableLayoutPanel4->Controls->Add(this->dev, 3, 4);
			this->tableLayoutPanel4->Controls->Add(this->button3, 2, 4);
			this->tableLayoutPanel4->Controls->Add(this->button2, 1, 4);
			this->tableLayoutPanel4->Controls->Add(this->button1, 0, 4);
			this->tableLayoutPanel4->Controls->Add(this->sum2, 4, 3);
			this->tableLayoutPanel4->Controls->Add(this->sum, 3, 3);
			this->tableLayoutPanel4->Controls->Add(this->button6, 2, 3);
			this->tableLayoutPanel4->Controls->Add(this->button5, 1, 3);
			this->tableLayoutPanel4->Controls->Add(this->button4, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->ave2, 4, 2);
			this->tableLayoutPanel4->Controls->Add(this->ave, 3, 2);
			this->tableLayoutPanel4->Controls->Add(this->button9, 2, 2);
			this->tableLayoutPanel4->Controls->Add(this->button8, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->button7, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->exp, 4, 1);
			this->tableLayoutPanel4->Controls->Add(this->f_e, 3, 1);
			this->tableLayoutPanel4->Controls->Add(this->clear, 2, 1);
			this->tableLayoutPanel4->Controls->Add(this->cad, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->bs, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->mm, 4, 0);
			this->tableLayoutPanel4->Controls->Add(this->mp, 3, 0);
			this->tableLayoutPanel4->Controls->Add(this->ms, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->mr, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->mc, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 206);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 6;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(359, 300);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// add
			// 
			this->add->Dock = System::Windows::Forms::DockStyle::Fill;
			this->add->Location = System::Drawing::Point(287, 248);
			this->add->Name = L"add";
			this->add->Size = System::Drawing::Size(69, 49);
			this->add->TabIndex = 29;
			this->add->Text = L"Add";
			this->add->UseVisualStyleBackColor = true;
			this->add->Click += gcnew System::EventHandler(this, &Calculator::add__Click);
			// 
			// inv
			// 
			this->inv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->inv->Location = System::Drawing::Point(216, 248);
			this->inv->Name = L"inv";
			this->inv->Size = System::Drawing::Size(65, 49);
			this->inv->TabIndex = 28;
			this->inv->Text = L"+/-";
			this->inv->UseVisualStyleBackColor = true;
			this->inv->Click += gcnew System::EventHandler(this, &Calculator::inv_Click);
			// 
			// dot
			// 
			this->dot->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dot->Location = System::Drawing::Point(145, 248);
			this->dot->Name = L"dot";
			this->dot->Size = System::Drawing::Size(65, 49);
			this->dot->TabIndex = 27;
			this->dot->Text = L".";
			this->dot->UseVisualStyleBackColor = true;
			this->dot->Click += gcnew System::EventHandler(this, &Calculator::dot_Click);
			// 
			// zero2
			// 
			this->zero2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zero2->Location = System::Drawing::Point(74, 248);
			this->zero2->Name = L"zero2";
			this->zero2->Size = System::Drawing::Size(65, 49);
			this->zero2->TabIndex = 26;
			this->zero2->Text = L"00";
			this->zero2->UseVisualStyleBackColor = true;
			this->zero2->Click += gcnew System::EventHandler(this, &Calculator::zero_Click);
			// 
			// zero
			// 
			this->zero->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zero->Location = System::Drawing::Point(3, 248);
			this->zero->Name = L"zero";
			this->zero->Size = System::Drawing::Size(65, 49);
			this->zero->TabIndex = 25;
			this->zero->Text = L"0";
			this->zero->UseVisualStyleBackColor = true;
			this->zero->Click += gcnew System::EventHandler(this, &Calculator::zero_Click);
			// 
			// pdev
			// 
			this->pdev->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pdev->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->pdev->Location = System::Drawing::Point(287, 199);
			this->pdev->Name = L"pdev";
			this->pdev->Size = System::Drawing::Size(69, 43);
			this->pdev->TabIndex = 24;
			this->pdev->Text = L"pdev(x)";
			this->pdev->UseVisualStyleBackColor = true;
			this->pdev->Click += gcnew System::EventHandler(this, &Calculator::pdev_Click);
			// 
			// dev
			// 
			this->dev->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dev->Location = System::Drawing::Point(216, 199);
			this->dev->Name = L"dev";
			this->dev->Size = System::Drawing::Size(65, 43);
			this->dev->TabIndex = 23;
			this->dev->Text = L"dev(x)";
			this->dev->UseVisualStyleBackColor = true;
			this->dev->Click += gcnew System::EventHandler(this, &Calculator::dev_Click);
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->Location = System::Drawing::Point(145, 199);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(65, 43);
			this->button3->TabIndex = 22;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button2->Location = System::Drawing::Point(74, 199);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(65, 43);
			this->button2->TabIndex = 21;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(3, 199);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(65, 43);
			this->button1->TabIndex = 20;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// sum2
			// 
			this->sum2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sum2->Location = System::Drawing::Point(287, 150);
			this->sum2->Name = L"sum2";
			this->sum2->Size = System::Drawing::Size(69, 43);
			this->sum2->TabIndex = 19;
			this->sum2->Text = L"sum(x^2)";
			this->sum2->UseVisualStyleBackColor = true;
			this->sum2->Click += gcnew System::EventHandler(this, &Calculator::sum2_Click);
			// 
			// sum
			// 
			this->sum->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sum->Location = System::Drawing::Point(216, 150);
			this->sum->Name = L"sum";
			this->sum->Size = System::Drawing::Size(65, 43);
			this->sum->TabIndex = 18;
			this->sum->Text = L"sum(x)";
			this->sum->UseVisualStyleBackColor = true;
			this->sum->Click += gcnew System::EventHandler(this, &Calculator::sum_Click);
			// 
			// button6
			// 
			this->button6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button6->Location = System::Drawing::Point(145, 150);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(65, 43);
			this->button6->TabIndex = 17;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// button5
			// 
			this->button5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button5->Location = System::Drawing::Point(74, 150);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(65, 43);
			this->button5->TabIndex = 16;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// button4
			// 
			this->button4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button4->Location = System::Drawing::Point(3, 150);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(65, 43);
			this->button4->TabIndex = 15;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// ave2
			// 
			this->ave2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ave2->Location = System::Drawing::Point(287, 101);
			this->ave2->Name = L"ave2";
			this->ave2->Size = System::Drawing::Size(69, 43);
			this->ave2->TabIndex = 14;
			this->ave2->Text = L"ave(x^2)";
			this->ave2->UseVisualStyleBackColor = true;
			this->ave2->Click += gcnew System::EventHandler(this, &Calculator::ave2_Click);
			// 
			// ave
			// 
			this->ave->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ave->Location = System::Drawing::Point(216, 101);
			this->ave->Name = L"ave";
			this->ave->Size = System::Drawing::Size(65, 43);
			this->ave->TabIndex = 13;
			this->ave->Text = L"ave(x)";
			this->ave->UseVisualStyleBackColor = true;
			this->ave->Click += gcnew System::EventHandler(this, &Calculator::ave_Click);
			// 
			// button9
			// 
			this->button9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button9->Location = System::Drawing::Point(145, 101);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(65, 43);
			this->button9->TabIndex = 12;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// button8
			// 
			this->button8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button8->Location = System::Drawing::Point(74, 101);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(65, 43);
			this->button8->TabIndex = 11;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// button7
			// 
			this->button7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button7->Location = System::Drawing::Point(3, 101);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(65, 43);
			this->button7->TabIndex = 10;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Calculator::num_Click);
			// 
			// exp
			// 
			this->exp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->exp->Location = System::Drawing::Point(287, 52);
			this->exp->Name = L"exp";
			this->exp->Size = System::Drawing::Size(69, 43);
			this->exp->TabIndex = 9;
			this->exp->Text = L"Exp";
			this->exp->UseVisualStyleBackColor = true;
			this->exp->Click += gcnew System::EventHandler(this, &Calculator::exp_Click);
			// 
			// f_e
			// 
			this->f_e->Dock = System::Windows::Forms::DockStyle::Fill;
			this->f_e->Location = System::Drawing::Point(216, 52);
			this->f_e->Name = L"f_e";
			this->f_e->Size = System::Drawing::Size(65, 43);
			this->f_e->TabIndex = 8;
			this->f_e->Text = L"F-E";
			this->f_e->UseVisualStyleBackColor = true;
			this->f_e->Click += gcnew System::EventHandler(this, &Calculator::f_e_Click);
			// 
			// clear
			// 
			this->clear->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clear->Location = System::Drawing::Point(145, 52);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(65, 43);
			this->clear->TabIndex = 7;
			this->clear->Text = L"C";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &Calculator::clear_Click);
			// 
			// cad
			// 
			this->cad->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cad->Location = System::Drawing::Point(74, 52);
			this->cad->Name = L"cad";
			this->cad->Size = System::Drawing::Size(65, 43);
			this->cad->TabIndex = 6;
			this->cad->Text = L"CAD";
			this->cad->UseVisualStyleBackColor = true;
			this->cad->Click += gcnew System::EventHandler(this, &Calculator::cad_Click);
			// 
			// bs
			// 
			this->bs->Dock = System::Windows::Forms::DockStyle::Fill;
			this->bs->Location = System::Drawing::Point(3, 52);
			this->bs->Name = L"bs";
			this->bs->Size = System::Drawing::Size(65, 43);
			this->bs->TabIndex = 5;
			this->bs->Text = L"←";
			this->bs->UseVisualStyleBackColor = true;
			this->bs->Click += gcnew System::EventHandler(this, &Calculator::bs_Click);
			// 
			// mm
			// 
			this->mm->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mm->Location = System::Drawing::Point(287, 3);
			this->mm->Name = L"mm";
			this->mm->Size = System::Drawing::Size(69, 43);
			this->mm->TabIndex = 4;
			this->mm->Text = L"M-";
			this->mm->UseVisualStyleBackColor = true;
			this->mm->Click += gcnew System::EventHandler(this, &Calculator::mm_Click);
			// 
			// mp
			// 
			this->mp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mp->Location = System::Drawing::Point(216, 3);
			this->mp->Name = L"mp";
			this->mp->Size = System::Drawing::Size(65, 43);
			this->mp->TabIndex = 3;
			this->mp->Text = L"M+";
			this->mp->UseVisualStyleBackColor = true;
			this->mp->Click += gcnew System::EventHandler(this, &Calculator::mp_Click);
			// 
			// ms
			// 
			this->ms->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ms->Location = System::Drawing::Point(145, 3);
			this->ms->Name = L"ms";
			this->ms->Size = System::Drawing::Size(65, 43);
			this->ms->TabIndex = 2;
			this->ms->Text = L"MS";
			this->ms->UseVisualStyleBackColor = true;
			this->ms->Click += gcnew System::EventHandler(this, &Calculator::ms_Click);
			// 
			// mr
			// 
			this->mr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mr->Location = System::Drawing::Point(74, 3);
			this->mr->Name = L"mr";
			this->mr->Size = System::Drawing::Size(65, 43);
			this->mr->TabIndex = 1;
			this->mr->Text = L"MR";
			this->mr->UseVisualStyleBackColor = true;
			this->mr->Click += gcnew System::EventHandler(this, &Calculator::mr_Click);
			// 
			// mc
			// 
			this->mc->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mc->Location = System::Drawing::Point(3, 3);
			this->mc->Name = L"mc";
			this->mc->Size = System::Drawing::Size(65, 43);
			this->mc->TabIndex = 0;
			this->mc->Text = L"MC";
			this->mc->UseVisualStyleBackColor = true;
			this->mc->Click += gcnew System::EventHandler(this, &Calculator::mc_Click);
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(365, 533);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Calculator";
			this->Text = L"Calculator";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: Boolean try_parse() {
			try{
				if(f_e->FlatStyle == System::Windows::Forms::FlatStyle::Flat)
					output->Text = Double::Parse(output->Text).ToString("E");
				else
					output->Text = Double::Parse(output->Text).ToString("F");
				return true;
			}catch(Exception^ e){
				output->Text = e->Message;
				output->ForeColor = Color::Red;
				return false;
			}
		 }
private: System::Void update_status() {
			 cnt->Text = String::Concat(L"Count = ",dataset->Items->Count.ToString());
			 if(!memory->Equals(0.0))
				 cnt->Text = String::Concat(cnt->Text,L"   M");
		 }
private: System::Void renew() {
			output->ForeColor = Color::Black;
			output->Text = L"0";
			exp->FlatStyle = System::Windows::Forms::FlatStyle::Standard;
			f_e->FlatStyle = System::Windows::Forms::FlatStyle::Standard;
		 }
private: System::Void try_renew() {
			 if(output->ForeColor != Color::Black){
				 renew();
			 }
		 }
private: System::Void num_Click(System::Object^  sender, System::EventArgs^  e) {
			 try_renew();
			 if(output->Text->Equals(L"0"))
				 output->Text = L"";
			 System::Windows::Forms::Button^  btn = (System::Windows::Forms::Button^) sender;
			 output->Text = String::Concat(output->Text,btn->Text);
		 }
private: System::Void dot_Click(System::Object^  sender, System::EventArgs^  e) {
			 try_renew();
			 if(output->Text->Contains(L"."))
				 return;
			 output->Text = String::Concat(output->Text,L".");
		 }
private: System::Void zero_Click(System::Object^  sender, System::EventArgs^  e) {
			 try_renew();
			 System::Windows::Forms::Button^  btn = (System::Windows::Forms::Button^) sender;
			 if(output->Text->Equals(L"0"))
				 return;
			 output->Text = String::Concat(output->Text,btn->Text);
		 }
private: System::Void bs_Click(System::Object^  sender, System::EventArgs^  e) {
			try_renew();
			
			if(output->Text->Length > 1)
				output->Text = output->Text->Substring(0,output->Text->Length - 1);
			else
				output->Text = L"0";
			if(output->Text->EndsWith(L"E+") || output->Text->EndsWith(L"E-"))
				output->Text = String::Concat(output->Text,"0");
		 }
private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e) {
			renew();
		 }
private: System::Void cad_Click(System::Object^  sender, System::EventArgs^  e) {
			dataset->Items->Clear();
			renew();
			update_status();
		 }
private: System::Void add__Click(System::Object^  sender, System::EventArgs^  e) {
			try_renew();
			if(!try_parse())
				return;
			if(dataset->SelectedItems->Count){
				dataset->Items[dataset->SelectedIndex] = output->Text->Clone();
				dataset->SetSelected(dataset->SelectedIndex,false);
			}
			else
				dataset->Items->Add(output->Text->Clone());
			update_status();
			renew();
		 }
private: System::Void inv_Click(System::Object^  sender, System::EventArgs^  e) {
			 try_renew();
			 if(f_e->FlatStyle == System::Windows::Forms::FlatStyle::Flat){
				 if(output->Text->Contains(L"E+"))
					output->Text = output->Text->Replace(L"E+",L"E-");
				 else
					output->Text = output->Text->Replace(L"E-",L"E+");
				 return;
			 }
			 if(output->Text->StartsWith(L"-"))
				 output->Text = output->Text->Substring(1,output->Text->Length - 1);
			 else
				 output->Text = String::Concat(L"-",output->Text);
		 }
private: System::Void f_e_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(f_e->FlatStyle == System::Windows::Forms::FlatStyle::Flat){
				 f_e->FlatStyle = System::Windows::Forms::FlatStyle::Standard;
				 try_parse();
				 return;
			 }
			 try_renew();
			 f_e->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			 try_parse();
		 }

private: System::Void exp_Click(System::Object^  sender, System::EventArgs^  e) {
			 try_renew();
			 if(f_e->FlatStyle == System::Windows::Forms::FlatStyle::Standard){
				f_e->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				output->Text = String::Concat(output->Text,"E+0");
			 }
		 }
private: System::Void mc_Click(System::Object^  sender, System::EventArgs^  e) {
			 memory = gcnew Double(0.0);
			 update_status();
		 }
private: System::Void mr_Click(System::Object^  sender, System::EventArgs^  e) {
			 output->Text = memory->ToString();
		 }
private: System::Void ms_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				*memory = Double::Parse(output->Text);
				update_status();
			 }catch(Exception^ e){
				output->Text = e->Message;
				output->ForeColor = Color::Red;
			 }
		 }
private: System::Void mp_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				*memory += Double::Parse(output->Text);
				update_status();
			 }catch(Exception^ e){
				output->Text = e->Message;
				output->ForeColor = Color::Red;
			 }
		 }
private: System::Void mm_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				*memory -= Double::Parse(output->Text);
				update_status();
			 }catch(Exception^ e){
				output->Text = e->Message;
				output->ForeColor = Color::Red;
			 }
		 }
private: System::Void ave_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(!dataset->Items->Count)
				 return;
			 Double^ sum = gcnew Double(0);
			 for each (String^ it in dataset->Items)
			 {
				 *sum += Double::Parse(it);
			 }
			 *sum = *sum / dataset->Items->Count;
			 output->Text = sum->ToString();
		 }
private: System::Void ave2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(!dataset->Items->Count)
				 return;
			 Double^ sum = gcnew Double(0);
			 Double^ temp = gcnew Double(0);
			 for each (String^ it in dataset->Items)
			 {
				 *temp = Double::Parse(it);
				 *temp *= *temp;
				 *sum += *temp;
			 }
			 *sum = *sum / dataset->Items->Count;
			 output->Text = sum->ToString();
		 }
private: System::Void sum_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(!dataset->Items->Count)
				 return;
			 Double^ sum = gcnew Double(0);
			 for each (String^ it in dataset->Items)
			 {
				 *sum += Double::Parse(it);
			 }
			 output->Text = sum->ToString();
		 }
private: System::Void sum2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(!dataset->Items->Count)
				 return;
			 Double^ sum = gcnew Double(0);
			 Double^ temp = gcnew Double(0);
			 for each (String^ it in dataset->Items)
			 {
				 *temp = Double::Parse(it);
				 *temp *= *temp;
				 *sum += *temp;
			 }
			 output->Text = sum->ToString();
		 }
private: System::Void dev_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(!dataset->Items->Count)
				 return;
			 Double^ average = gcnew Double(0);
			 Double^ temp = gcnew Double(0);
			 System::Collections::ArrayList^ items = gcnew System::Collections::ArrayList(dataset->Items->Count);;
			 for each (String^ it in dataset->Items)
			 {
				 *temp = Double::Parse(it);
				 *average += *temp;
				 items->Add(gcnew Double(*temp));
			 }
			 *average = *average / dataset->Items->Count;
			 Double^ dev = gcnew Double(0);
			 for each (Double^ it in items)
			 {
				 *dev += (*it - *average)*(*it - *average);
			 }
			 output->Text = Math::Sqrt(*dev/items->Count).ToString();
		 }
private: System::Void pdev_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(dataset->Items->Count <= 1)
				 return;
			 Double^ average = gcnew Double(0);
			 Double^ temp = gcnew Double(0);
			 System::Collections::ArrayList^ items = gcnew System::Collections::ArrayList(dataset->Items->Count);;
			 for each (String^ it in dataset->Items)
			 {
				 *temp = Double::Parse(it);
				 *average += *temp;
				 items->Add(gcnew Double(*temp));
			 }
			 *average = *average / dataset->Items->Count;
			 Double^ dev = gcnew Double(0);
			 for each (Double^ it in items)
			 {
				 *dev += (*it - *average)*(*it - *average);
			 }
			 output->Text = Math::Sqrt(*dev/(items->Count-1)).ToString();
		 }
private: System::Void prev_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(dataset->Items->Count){
				 if(dataset->SelectedItems->Count){
					 if(dataset->SelectedIndex != 0)
						dataset->SelectedIndex--;
				 }
				 else
					 dataset->SelectedIndex = dataset->Items->Count - 1;
			 }
		 }
private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(dataset->Items->Count){
				 if(dataset->SelectedItems->Count){
					 if(dataset->SelectedIndex != dataset->Items->Count - 1)
						dataset->SelectedIndex++;
				 }
				 else
					dataset->SelectedIndex = 0;
			 }
		 }
private: System::Void about_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show(L"簡易的統計計算機 \n=========================\n\n就是個簡易的統計計算機，為了 103年 視窗程式設計作業 HW5 而生  \n\n## 按鈕說明\n\n * `0`,`00` ~ `9` 以及 `.`: 輸入數字內容\n * `F-E`: 數字表示 / 科學記號表示 切換\n * `Exp`: 進行科學記號輸入\n * `+/-`: 切換正負 (F-E 開啟時將替指數部分進行正負切換)\n * `←`: 退格 (backspace)\n * `Add`: 把目前輸入內容加入資料列\n * `C`: 清除目前輸入內容\n * `CAD`: 清除目前輸入內容以及資料列\n * `ave(x)`: 計算資料列的平均值\n * `ave(x^2)`: 計算資料列的平方平均值\n * `sum(x)`: 計算資料列的總和\n * `sum(x^2)`: 計算資料列的平方總和\n * `dev(x^2)`: 計算資料列的標準差\n * `pdev(x^2)`: 計算資料列的母體標準差\n * `MC`: Memory Clear, 清除記憶數字為零\n * `MR`: Memory Recall, 將記憶中的數字喚回輸入框\n * `MS`: Memory Set, 記憶目前輸入框的內容\n * `M+`: Memory Addition, 將目前輸入框內容加入記憶數字\n * `M-`: Memory Subtraction, 將目前輸入框內容減入記憶數字\n * `↑`: 選擇資料列的上一個項目\n * `↓`: 選擇資料列的下一個項目\n\n## 操作說明\n\n * 輸入數字內容到輸入框之後，按下 `Add` 加入資料列\n * 若選擇資料列中的一個項目 (單擊項目)，按下 `Add` 時將修改該項目的數值\n * 在資料列框框內任何地方雙擊將取消選取\n * 記憶數字不為空 (數值不為零) 時，Count 右方會顯示 `M` 表示目前記憶有內容\n\n## 作者資訊\n\n * 4101056017 邱冠喻 第五次作業 12/10\n * 4101056017 Chiu Guan-Yu TheFifthHomework 12/10\n * PastLeo\n * chgu82837@gmail.com\n");
		 }
private: System::Void dataset_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(dataset->SelectedItems->Count)
				dataset->SetSelected(dataset->SelectedIndex,false);
		 }
};
}

/***************************
4101056017 邱冠喻 第五次作業 12/10
4101056017 Chiu Guan-Yu TheFifthHomework 12/10
***************************/