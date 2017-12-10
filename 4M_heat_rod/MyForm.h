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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::DataGridView^  dataGridView2;





	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

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
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
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
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Area;
			series3->Legend = L"Legend1";
			series3->Name = L"Series3";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(637, 364);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 67);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(199, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Solve";
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
			this->dataGridView1->Size = System::Drawing::Size(708, 364);
			this->dataGridView1->TabIndex = 2;
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
			this->textBox1->Location = System::Drawing::Point(105, 44);
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
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(231, 409);
			this->chart2->Name = L"chart2";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series5->Legend = L"Legend1";
			series5->Name = L"Series2";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Area;
			series6->Legend = L"Legend1";
			series6->Name = L"Series3";
			series6->YValuesPerPoint = 2;
			this->chart2->Series->Add(series4);
			this->chart2->Series->Add(series5);
			this->chart2->Series->Add(series6);
			this->chart2->Size = System::Drawing::Size(637, 364);
			this->chart2->TabIndex = 5;
			this->chart2->Text = L"chart2";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dataGridView2->Location = System::Drawing::Point(732, 409);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(708, 364);
			this->dataGridView2->TabIndex = 6;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->FillWeight = 40;
			this->dataGridViewTextBoxColumn1->HeaderText = L"node";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 40;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->FillWeight = 40;
			this->dataGridViewTextBoxColumn2->HeaderText = L"x";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 40;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->FillWeight = 200;
			this->dataGridViewTextBoxColumn3->HeaderText = L"u(x)";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 200;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->FillWeight = 200;
			this->dataGridViewTextBoxColumn4->HeaderText = L"v(x)";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 200;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->FillWeight = 250;
			this->dataGridViewTextBoxColumn5->HeaderText = L"error";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 250;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 511);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 17);
			this->label2->TabIndex = 9;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(105, 441);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(120, 22);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"10";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(26, 464);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(199, 32);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Solve";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"amo of iters";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 444);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"amo of iters";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(65, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(114, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"GENERAL TASK";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(77, 409);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 17);
			this->label6->TabIndex = 13;
			this->label6->Text = L"TEST TASK";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1463, 798);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
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
		double eps = 0.0000005, eps_gen;
		double xeps2, __a = 0., b = 1.0, ksi = 0.5, *d;
		double *fi, *a, *v, *d2, *fi2, *a2, *v2;
		while (true) {
			eps_gen = 0.0;
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
				if (fabs(v[i] - v2[2 * i]) > eps_gen) {
					eps_gen = fabs(v[i] - v2[2 * i]);
					xeps2 = (double)i / dim;
				}
			if (eps_gen <= eps) break;
			dim *= 2;
		}
				for (int i = 0; i <= dim; ++i) {
					chart1->Series["Series1"]->Points->AddXY((double)i / dim, v[i]);
					chart1->Series["Series2"]->Points->AddXY((double)i / dim, v2[2 * i]);
					chart1->Series["Series3"]->Points->AddXY((double)i / dim, fabs(1000000.*(v[i] - v2[2 * i])));

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
			+ Convert::ToString(eps_gen) + "; "
			+ "\nћаксимальна€ разность\n численных решений\n в общих узлах сетки\n наблюдаетс€ в точке\n x = " 
			+ Convert::ToString(xeps2) + "; ";

	}
	private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	dim = Convert::ToInt64(textBox2->Text);
	double eps = 0.0000005, eps_test = 0.;
	double xeps1, ksi = 0.5, *d, *fi, *a, *v;
		
	while (true) 
	{
		eps_test = 0.;
		d = new double[dim];
		fi = new double[dim];
		a = new double[dim + 1];
		v = new double[dim + 1];
	
		_calc_coef(dim, ksi, d, fi, a, _k1_t, _k2_t, _f1_t, _f2_t, _q1_t, _q2_t);
		rush(dim, a, d, fi, v);
		for (int i = 0; i <= dim; ++i)
			if (fabs(_true_sol((double)i / dim, ksi) - v[i]) > eps_test) 
			{
				eps_test = fabs(_true_sol((double)i / dim, ksi) - v[i]);
				xeps1 = (double)i / dim;
			}
		if (eps_test <= eps) break;
		dim *= 2;
	
	}
		for (int i = 0; i <= dim; ++i) 
		{
			chart2->Series["Series1"]->Points->AddXY((double)i / dim, v[i]);
			chart2->Series["Series2"]->Points->AddXY((double)i / dim, _true_sol((double)i / dim, ksi));
			chart2->Series["Series3"]->Points->AddXY((double)i / dim, fabs(1.22*_true_sol((double)i / dim, ksi) - v[i]));

			dataGridView2->Rows->Add();
			dataGridView2->Rows[i]->Cells[0]->Value = Convert::ToString(i);
			dataGridView2->Rows[i]->Cells[1]->Value = Convert::ToString(i * _step);
			dataGridView2->Rows[i]->Cells[2]->Value = Convert::ToString(_true_sol((double)i / dim, ksi));
			dataGridView2->Rows[i]->Cells[3]->Value = Convert::ToString(v[i]);
			dataGridView2->Rows[i]->Cells[4]->Value = Convert::ToString(_true_sol((double)i / dim, ksi) - v[i]);
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


		label2->Text = "ƒл€ решени€ задачи\n  использована равномерна€\n  сетка с числом разбиений\n  n = "
			+ Convert::ToString(dim) + "; "
			"\n«адача должна быть решена с\n заданной точностью\n eps = 0.5*10^Ц7;\n задача решена с точностью\n eps2 ="
			+ Convert::ToString(eps_test) + "; "
			+ "\nћаксимальна€ разность\n численных решений\n в общих узлах сетки\n наблюдаетс€ в точке\n x = "
			+ Convert::ToString(xeps1) + "; ";
}
};
}
