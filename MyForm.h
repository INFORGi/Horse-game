#pragma once

#include <cstdlib>
#include <ctime>

namespace HorseRace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

			// ������������� ���������� ��������� �����
			srand(static_cast<unsigned int>(time(0)));

			// ������������� ������� ��� ��� ������ � ������ ������
			playerHorsePairs = gcnew array<String^, 2>(MAX_PLAYERS, 2);

			// ������������� ����������
			playerCount = 0;
			raceCount = 0;
			horsePoints = gcnew array<int>(MAX_HORSES);
			horsePosition = gcnew array<int>(MAX_HORSES);
			for (int i = 0; i < MAX_HORSES; i++) {
				horsePoints[i] = 0;
				horsePosition[i] = 0;
			}

			selectedHorses = gcnew array<int>(MAX_PLAYERS);
			for (int i = 0; i < MAX_PLAYERS; i++) {
				selectedHorses[i] = 0;
			}

			// �������������� ������
			timer1 = gcnew Timer();
			timer1->Interval = 100; // �������� � ������������� (100 ��)
			timer1->Tick += gcnew EventHandler(this, &MyForm::Timer_Tick);
		}


	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ AddPlayer;
	private: System::Windows::Forms::Button^ RandomAddPlayer;
	private: System::Windows::Forms::Button^ ClearArrayPlayer;
	private: System::Windows::Forms::Button^ Start;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ NamePlayer;
	private: System::Windows::Forms::TextBox^ NumberHorse;
	private: System::Windows::Forms::ListBox^ ArrayPlayer;
	private: System::Windows::Forms::Panel^ ArenaGame;


	protected:

	private:
		System::ComponentModel::Container^ components;
	private:
		System::Windows::Forms::Timer^ timer1;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->AddPlayer = (gcnew System::Windows::Forms::Button());
			this->RandomAddPlayer = (gcnew System::Windows::Forms::Button());
			this->ClearArrayPlayer = (gcnew System::Windows::Forms::Button());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NamePlayer = (gcnew System::Windows::Forms::TextBox());
			this->NumberHorse = (gcnew System::Windows::Forms::TextBox());
			this->ArrayPlayer = (gcnew System::Windows::Forms::ListBox());
			this->ArenaGame = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// AddPlayer
			// 
			this->AddPlayer->BackColor = System::Drawing::Color::MediumTurquoise;
			this->AddPlayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddPlayer->Location = System::Drawing::Point(12, 12);
			this->AddPlayer->Name = L"AddPlayer";
			this->AddPlayer->Size = System::Drawing::Size(206, 63);
			this->AddPlayer->TabIndex = 0;
			this->AddPlayer->Text = L"�������� ������";
			this->AddPlayer->UseVisualStyleBackColor = false;
			this->AddPlayer->Click += gcnew System::EventHandler(this, &MyForm::AddPlayer_Click);
			// 
			// RandomAddPlayer
			// 
			this->RandomAddPlayer->BackColor = System::Drawing::Color::PaleTurquoise;
			this->RandomAddPlayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RandomAddPlayer->Location = System::Drawing::Point(12, 81);
			this->RandomAddPlayer->Name = L"RandomAddPlayer";
			this->RandomAddPlayer->Size = System::Drawing::Size(206, 63);
			this->RandomAddPlayer->TabIndex = 1;
			this->RandomAddPlayer->Text = L"��������� ����������";
			this->RandomAddPlayer->UseVisualStyleBackColor = false;
			this->RandomAddPlayer->Click += gcnew System::EventHandler(this, &MyForm::RandomAddPlayer_Click);
			// 
			// ClearArrayPlayer
			// 
			this->ClearArrayPlayer->BackColor = System::Drawing::Color::Crimson;
			this->ClearArrayPlayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ClearArrayPlayer->Location = System::Drawing::Point(12, 150);
			this->ClearArrayPlayer->Name = L"ClearArrayPlayer";
			this->ClearArrayPlayer->Size = System::Drawing::Size(206, 63);
			this->ClearArrayPlayer->TabIndex = 2;
			this->ClearArrayPlayer->Text = L"������� ����������";
			this->ClearArrayPlayer->UseVisualStyleBackColor = false;
			this->ClearArrayPlayer->Click += gcnew System::EventHandler(this, &MyForm::ClearArrayPlayer_Click);
			// 
			// Start
			// 
			this->Start->BackColor = System::Drawing::SystemColors::HotTrack;
			this->Start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Start->Location = System::Drawing::Point(224, 12);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(206, 63);
			this->Start->TabIndex = 3;
			this->Start->Text = L"������ �����";
			this->Start->UseVisualStyleBackColor = false;
			this->Start->Click += gcnew System::EventHandler(this, &MyForm::Start_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 280);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"���";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 318);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"����� ����";
			// 
			// NamePlayer
			// 
			this->NamePlayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NamePlayer->Location = System::Drawing::Point(116, 274);
			this->NamePlayer->Multiline = true;
			this->NamePlayer->Name = L"NamePlayer";
			this->NamePlayer->Size = System::Drawing::Size(225, 32);
			this->NamePlayer->TabIndex = 6;
			this->NamePlayer->TextChanged += gcnew System::EventHandler(this, &MyForm::NamePlayer_TextChanged);
			// 
			// NumberHorse
			// 
			this->NumberHorse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberHorse->Location = System::Drawing::Point(116, 312);
			this->NumberHorse->Multiline = true;
			this->NumberHorse->Name = L"NumberHorse";
			this->NumberHorse->Size = System::Drawing::Size(225, 32);
			this->NumberHorse->TabIndex = 7;
			// 
			// ArrayPlayer
			// 
			this->ArrayPlayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ArrayPlayer->FormattingEnabled = true;
			this->ArrayPlayer->ItemHeight = 25;
			this->ArrayPlayer->Location = System::Drawing::Point(16, 368);
			this->ArrayPlayer->Name = L"ArrayPlayer";
			this->ArrayPlayer->Size = System::Drawing::Size(414, 629);
			this->ArrayPlayer->TabIndex = 8;
			// 
			// ArenaGame
			// 
			this->ArenaGame->BackColor = System::Drawing::Color::Green;
			this->ArenaGame->Location = System::Drawing::Point(449, 3);
			this->ArenaGame->Name = L"ArenaGame";
			this->ArenaGame->Size = System::Drawing::Size(1452, 1035);
			this->ArenaGame->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Beige;
			this->ClientSize = System::Drawing::Size(1920, 1061);
			this->Controls->Add(this->NamePlayer);
			this->Controls->Add(this->NumberHorse);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->ArenaGame);
			this->Controls->Add(this->ArrayPlayer);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ClearArrayPlayer);
			this->Controls->Add(this->RandomAddPlayer);
			this->Controls->Add(this->AddPlayer);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// ���������
		static const int MAX_PLAYERS = 10;
		static const int MAX_HORSES = 10;

	private: array<int>^ selectedHorses;

		   // ����������
		   array<String^, 2>^ playerHorsePairs;
		   int playerCount;
		   int raceCount;
		   array<int>^ horsePoints;
		   array<int>^ horsePosition;
		   int winningHorseIndex = -1;
		   int raceCompletedCount = 0;

		   // ���������, ������ �� ��� ���� � ��������� �������
		   bool IsHorseNumberSelected(int horseNumber) {
			   for (int i = 0; i < playerCount; i++) {
				   if (playerHorsePairs[i, 1] == horseNumber.ToString()) {
					   return true; // ������ ��������� ����� ����
				   }
			   }
			   return false; // ����� ���� ��� �� ������
		   }

		   // ����� ��� �������� � ���������� �������� �� �����
		   void CreateGameObjects() {
			   // ���� � �����������
			   String^ imagePath = "D:/3 ����/��2/C++/Horse/img/pngwing.com.png";

			   // ���������, ���������� �� ���� �����������
			   if (System::IO::File::Exists(imagePath)) {
				   // ���������� ����� ���������� �����
				   int totalHorses = MAX_HORSES;

				   // ��������� ������ ������ ArenaGame
				   int arenaHeight = this->ArenaGame->Height;
				   int objectHeight = 60;
				   int objectWidth = 60;

				   // ��������� ���������� ����� ��������� ������ �� ���������� ����� � ������ ������
				   int spacing = (arenaHeight - totalHorses * objectHeight) / (totalHorses + 1);

				   // ������� ������� � ������� �� ������ ArenaGame
				   for (int i = 0; i < totalHorses; i++) {
					   // ������� ��������� PictureBox � ������������� ������� �����������
					   PictureBox^ pictureBox = gcnew PictureBox();
					   pictureBox->Image = Image::FromFile(imagePath);

					   // ������������� ������ �������
					   pictureBox->Size = System::Drawing::Size(objectWidth, objectHeight);

					   // ������������ ������� �������
					   int x = 5; // ������� X (������ �������� �� ������ ����������)
					   int y = (i + 1) * spacing + i * objectHeight; // ������� Y

					   // ������������� ������� ������� �� ������ ArenaGame
					   pictureBox->Location = System::Drawing::Point(x, y);

					   // ��������� ����������� ����������� � PictureBox
					   pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;

					   // ������������� ���� ���� ��� ������� PictureBox
					   pictureBox->BackColor = Color::Transparent;

					   // ��������� PictureBox �� ������ ArenaGame
					   this->ArenaGame->Controls->Add(pictureBox);
				   }
			   }
			   else {
				   // ���� ���� ����������� �� ������, ������� ��������� �� ������
				   MessageBox::Show("���� ����������� �� ������.");
			   }
		   }

private: System::Void MoveHorses() {
	// ���������� ��� �����������, ������ �� ���� ���� ���� ����� �����
	bool isRaceFinished = false;

	// ���������� ������� ���� �� ��������� ���������� ������ (�� 1 �� 15 ������)
	for each (Control ^ control in ArenaGame->Controls) {
		if (PictureBox^ pictureBox = dynamic_cast<PictureBox^>(control)) {
			// ���������, ������ �� ���� ����� �����
			if (pictureBox->Location.X + pictureBox->Width >= ArenaGame->Width) {
				// ������������� ���� ��� ���������� ������� �����
				pictureBox->Left = ArenaGame->Width - pictureBox->Width;
				isRaceFinished = true; // ���� ��, ������������� ���� � ���������� �����
				// �������� ������ ����������� ���� � ��������� ���
				winningHorseIndex = ArenaGame->Controls->IndexOf(pictureBox);
				// ��������� ���� ���� ������ � ������ ������
				horsePoints[winningHorseIndex] += 5;
			}
			else {
				// ���������� ��������� ����� �� 1 �� 33 ��� ����������� ����
				int moveDistance = rand() % 33 + 1;
				// ���������� ���� �� ��������� ���������� ������
				pictureBox->Left += moveDistance;
			}
		}
	}

	// ���� ���� ������ ����� �����, ������� ��������� � ���������� �����
	if (isRaceFinished) {
		timer1->Stop();

		// �������������� ��������� � ���������� ����� � ����������� � ����� � �� �����
		String^ raceResultMessage = "����� ���������! ����������:\n";
		for (int i = 0; i < MAX_HORSES; i++) {
			raceResultMessage += "���� " + (i + 1) + ": " + horsePoints[i] + " �����\n";
		}
		MessageBox::Show(raceResultMessage);

		raceCompletedCount++; // ����������� ���������� ����������� �������

		// ���� ��� ������ ���������, ������������� ������
		if (raceCompletedCount == 5) {
			timer1->Stop();
			
			int maxPointsIndex = 0;
			bool isDraw = true;
			for (int i = 1; i < MAX_HORSES; i++) {
				if (horsePoints[i] > horsePoints[maxPointsIndex]) {
					maxPointsIndex = i;
					isDraw = false;
				}
				else if (horsePoints[i] < horsePoints[maxPointsIndex]) {
					isDraw = false; // ���� ����� ������ � ������� ����������� �����, �� �� �����
				}
			}

			if (isDraw) {
				MessageBox::Show("����� ����������� ������!");
				return;
			}


			// ������� ��� ������, ���������� � ������� � ������������ ����������� �����
			String^ winnerName = playerHorsePairs[maxPointsIndex, 0];
			MessageBox::Show("��� ������ ���������! ����������: " + winnerName + ", ������: " + (winningHorseIndex + 1));
		}
	}

	// ���� ����� �������� ��� ��� ������ �����, ���������� ���� ����� ������� � ������ �����
	if (isRaceFinished) {
		for each (Control ^ control in ArenaGame->Controls) {
			if (PictureBox^ pictureBox = dynamic_cast<PictureBox^>(control)) {
				pictureBox->Location = Point(5, pictureBox->Location.Y);
			}
		}
	}

	// ���� �� ��� ������ ���������, ��������� ������ ��� ���������� ������
	if (raceCompletedCount < 5) {
		timer1->Start();
	}
	else
	{
		raceCompletedCount = 0;
	}
}


	private:System::Void Timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		MoveHorses();
	}
		   // ���������� ������ � ���������� �������
	private: System::Void AddPlayer_Click(System::Object^ sender, System::EventArgs^ e) {
		// ���������, ��� � ������� ��� ���� ��������� �����
		if (playerCount >= MAX_PLAYERS) {
			MessageBox::Show("��� ��������� ��������������.");
			return;
		}

		// ���������, ��� ��� ��������� ���� ���������
		if (NamePlayer->Text == "" || NumberHorse->Text == "") {
			MessageBox::Show("����������, ��������� ��� ����.");
			return;
		}

		// ���������, ��� � ���� ������ ���� ������� ������ �����
		for each (char c in NumberHorse->Text) {
			if (!Char::IsDigit(c)) {
				MessageBox::Show("����� ���� ������ ��������� ������ �����.");
				return;
			}
		}


		int horseNumber = Convert::ToInt32(NumberHorse->Text);

		// ���������, ��� ����� ���� ��������� � ��������� �� 1 �� 10
		if (horseNumber < 1 || horseNumber > MAX_HORSES) {
			MessageBox::Show("����� ���� ������ ���� �� 1 �� 10.");
			return;
		}

		// ���������, ��� ����� ���� �� ������ ������ �������
		if (IsHorseNumberSelected(horseNumber)) {
			MessageBox::Show("���� ����� ���� ��� ������ ������ �������.");
			return;
		}

		// ��������� ��� ������ � ����� ���� � ������
		playerHorsePairs[playerCount, 0] = NamePlayer->Text;
		playerHorsePairs[playerCount, 1] = NumberHorse->Text;
		// ��������� ���������� �� ������ � ������
		ArrayPlayer->Items->Add(playerHorsePairs[playerCount, 0] + ", ���� " + playerHorsePairs[playerCount, 1]);
		// ����������� ������� �������
		playerCount++;
		// ������� ��������� ����
		NamePlayer->Text = "";
		NumberHorse->Text = "";
	}

		   // ���������� ������ � ���������� �������
	private: System::Void RandomAddPlayer_Click(System::Object^ sender, System::EventArgs^ e) {
		// ���������, ��� � ������� ��� ���� ��������� �����
		if (playerCount >= MAX_PLAYERS) {
			MessageBox::Show("��� ����� � ������� ��� ���������.");
			return;
		}

		// ��������� ��������� ������� ���������� ������ ����� � �������
		for (int i = playerCount; i < MAX_PLAYERS; i++) {
			int horseNumber;
			do {
				horseNumber = rand() % MAX_HORSES + 1;
			} while (IsHorseNumberSelected(horseNumber)); // ���������, ��� ��������� ����� ���� ��� �� �����������

			playerHorsePairs[i, 0] = "����� " + (i + 1); // ���������� ��� ������
			playerHorsePairs[i, 1] = horseNumber.ToString();
			// ��������� ���������� �� ������ � ������
			ArrayPlayer->Items->Add(playerHorsePairs[i, 0] + ", ���� " + playerHorsePairs[i, 1]);
			playerCount++; // ����������� ������� �������
		}
	}

	private: System::Void ClearArrayPlayer_Click(System::Object^ sender, System::EventArgs^ e) {
		// ������� ������ � ������
		ArrayPlayer->Items->Clear();
		playerCount = 0;
		raceCount = 0;
		for (int i = 0; i < MAX_HORSES; i++) {
			horsePoints[i] = 0;
			horsePosition[i] = 0;
		}
	}

	private: System::Void Start_Click(System::Object^ sender, System::EventArgs^ e) {
		if (playerCount == 10) {
			ArenaGame->Controls->Clear();
			CreateGameObjects();
			for (int i = 0; i < MAX_HORSES; i++) {
				horsePoints[i] = 0;
			}
			timer1->Start();
		}
		else {
			MessageBox::Show("������ ���� 10 ����������!");
		}
	}
	private: System::Void NamePlayer_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
