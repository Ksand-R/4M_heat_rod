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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(31, 37);
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
			this->chart1->Size = System::Drawing::Size(1137, 740);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1174, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(262, 59);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1463, 798);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//		std::ofstream filetable, fileref;
		//		filetable.open("maintable.txt");
		//		fileref.open("mainref.txt");
		int n = 10;
		double eps = 0.0000005, eps2;
		double xeps2, __a = 0., b = 1.0, ksi = 0.5, mu1 = 1., mu2 = 1., *d,
			*fi, *a, *v, *d2, *fi2, *a2, *v2;
		while (true) {
			eps2 = 0.0;
			d = new double[n];
			fi = new double[n];
			a = new double[n + 1];
			v = new double[n + 1];

			_calc_coef(n, ksi, d, fi, a, _k1, _k2, _f1, _f2, _q1, _q2);
			rush(n, a, d, fi, v);

			d2 = new double[2 * n];
			fi2 = new double[2 * n];
			a2 = new double[2 * n + 1];
			v2 = new double[2 * n + 1];

			_calc_coef(2 * n, ksi, d2, fi2, a2, _k1, _k2, _f1, _f2, _q1, _q2);
			rush(2 * n, a2, d2, fi2, v2);

			for (int i = 0; i <= n; ++i)
				if (fabs(v[i] - v2[2 * i]) > eps2) {
					eps2 = fabs(v[i] - v2[2 * i]);
					xeps2 = __a + (b - __a) * i / n;
				}
			if (eps2 <= eps) break;
			n *= 2;
		}
		//		fileref << n << ' ' << eps2 << ' ' << xeps2;
				for (int i = 0; i <= n; ++i) {
		//			filetable << __a + ((b - __a) / n)*i << ' ' << v[i] << ' ' << v2[2 * i] << ' ' << v[i] - v2[2 * i] << std::endl;
					chart1->Series["Series1"]->Points->AddXY(__a + (b - __a)* i / n, v[i]);
					chart1->Series["Series2"]->Points->AddXY(__a + (b - __a)* i / n, v2[2 * i]);
		//chart3->Series["Series1"]->Points->AddXY(__a + (b - __a) * i / n, v[i] - v2[2 * i]);
				}
		delete[] d;
		delete[] fi;
		delete[] a;
		delete[] v;
		delete[] d2;
		delete[] fi2;
		delete[] a2;
		delete[] v2;
	}
	};
}
