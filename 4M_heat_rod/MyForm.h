#pragma once
#include "Balance.h"
namespace My4M_heat_rod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	int _NSeries = 0;
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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(231, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(637, 391);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(199, 59);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(732, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(708, 391);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->FillWeight = 40;
			this->Column1->HeaderText = L"node";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 40;
			// 
			// Column2
			// 
			this->Column2->FillWeight = 40;
			this->Column2->HeaderText = L"x";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 40;
			// 
			// Column3
			// 
			this->Column3->FillWeight = 200;
			this->Column3->HeaderText = L"v(x)";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 200;
			// 
			// Column4
			// 
			this->Column4->FillWeight = 200;
			this->Column4->HeaderText = L"v2(x)";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 200;
			// 
			// Column5
			// 
			this->Column5->FillWeight = 250;
			this->Column5->HeaderText = L"error";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 250;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(26, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 22);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"10";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 114);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 17);
			this->label1->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1463, 798);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//DataVisualization::Charting::Series^ s = gcnew DataVisualization::Charting::Series;
		//chart1->Series->Add(s);
		//s->BorderWidth = 2;
		//s->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		//int* NSeries = &_NSeries;

		dim = Convert::ToInt64(textBox1->Text);
		double eps = 0.0000005, eps2;
		double xeps2, __a = 0., b = 1.0, ksi = 0.5, mu1 = 1., mu2 = 1., *d,
			*fi, *a, *v, *d2, *fi2, *a2, *v2;
		while (true) {
			eps2 = 0.0;
			d = new double[dim];
			fi = new double[dim];
			a = new double[dim + 1];
			v = new double[dim + 1];

			_calc_coef(dim, ksi, d, fi, a, _k1, _k2, _f1, _f2, _q1, _q2);
			rush(dim, a, d, fi, v);

			d2 = new double[2 * dim];
			fi2 = new double[2 * dim];
			a2 = new double[2 * dim + 1];
			v2 = new double[2 * dim + 1];

			_calc_coef(2 * dim, ksi, d2, fi2, a2, _k1, _k2, _f1, _f2, _q1, _q2);
			rush(2 * dim, a2, d2, fi2, v2);

			for (int i = 0; i <= dim; ++i)
				if (fabs(v[i] - v2[2 * i]) > eps2) {
					eps2 = fabs(v[i] - v2[2 * i]);
					xeps2 = (double)i / dim;
				}
			if (eps2 <= eps) break;
			dim *= 2;
		}
				for (int i = 0; i <= dim; ++i) {
					chart1->Series["Series1"]->Points->AddXY((double)i / dim, v[i]);
					chart1->Series["Series2"]->Points->AddXY((double)i / dim, v2[2 * i]);

					dataGridView1->Rows->Add(); 
					dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(i);
					dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(i * _step);
					dataGridView1->Rows[i]->Cells[2]->Value = Convert::ToString(v[i]);
					dataGridView1->Rows[i]->Cells[3]->Value = Convert::ToString(v2[2 * i]);
					dataGridView1->Rows[i]->Cells[4]->Value = Convert::ToString(v[i] - v2[2 * i]);

					//chart1->Series[*NSeries]->Points->AddXY((double)i / dim, v[i]);
					//(*NSeries)++;
					//chart1->Series[*NSeries]->Points->AddXY((double)i / dim, v2[2 * i]);
					//(*NSeries)--;
				}
		//		(*NSeries)++;
		delete[] d;
		delete[] fi;
		delete[] a;
		delete[] v;
		delete[] d2;
		delete[] fi2;
		delete[] a2;
		delete[] v2;

		label1->Text = "ƒл€ решени€ задачи\n  использована равномерна€\n  сетка с числом разбиений\n  n = " 
			+ Convert::ToString(dim) + "; "
			"\n«адача должна быть решена с\n заданной точностью\n eps = 0.5*10^Ц7;\n задача решена с точностью\n eps2 =" 
			+ Convert::ToString(eps2) + "; "
			+ "\nћаксимальна€ разность\n численных решений\n в общих узлах сетки\n наблюдаетс€ в точке\n x = " 
			+ Convert::ToString(xeps2) + "; ";




	}
	private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
};
}
