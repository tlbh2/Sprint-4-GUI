#include "cMain.h"
//this is about the window

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(2002, cMain::Restart)
EVT_BUTTON(3003, cMain::AI_OnButtonClicked)
EVT_TEXT_ENTER(1000, cMain::BoardSize)
EVT_RADIOBUTTON(1001, cMain::Simple_game_Checked)
EVT_RADIOBUTTON(1002, cMain::General_game_Checked)
EVT_RADIOBUTTON(1011, cMain::Bplayer_S_Checked)
EVT_RADIOBUTTON(1022, cMain::Bplayer_O_Checked)
EVT_RADIOBUTTON(1033, cMain::Rplayer_S_Checked)
EVT_RADIOBUTTON(1044, cMain::Rplayer_O_Checked)
EVT_RADIOBUTTON(1055, cMain::Bplayer_Human_Checked)
EVT_RADIOBUTTON(1066, cMain::Bplayer_AI_Checked)
EVT_RADIOBUTTON(1077, cMain::Rplayer_Human_Checked)
EVT_RADIOBUTTON(1088, cMain::Rplayer_AI_Checked)

wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "SOS Game", wxPoint(40, 40), wxSize(600, 350))
{
	UI_object->GameLogic_object->SetCurrentPlayer(UI_object->GameLogic_object->Bplayer);
	previous_game_winner = UI_object->GameLogic_object->Bplayer;
	InitializeComponent();
}

cMain::~cMain()
{
	//prevent memory leak
	delete[]UI_object->btn;
}

//Event function definition

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	//Get coordinate of button in field array
	int x = (evt.GetId() - 10000) % UI_object->get_Length();
	int y = (evt.GetId() - 10000) / UI_object->get_Length();
	string temp_Label;
	pair<int, int> temp_pair;
	
	if (UI_object->GameLogic_object->GetGameMode() == "SimpleGame")
	{
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Human" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Human")
		{
			if (UI_object->GameLogic_object->GetCurrentPlayer() == UI_object->GameLogic_object->Bplayer)
			{
				//set label to button once pressed
				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->GameLogic_object->Get_Bplayer_Label());
				UI_object->GameLogic_object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->GameLogic_object->Get_Bplayer_Label();

				temp_Label = UI_object->GameLogic_object->Get_Bplayer_Label();
				if (temp_Label == "O")
				{
					//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
					//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);
					
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);

					if (UI_object->is_that_an_SOS == true)
					{
						wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
						UI_object->is_that_an_SOS = false;
						previous_game_winner = UI_object->GameLogic_object->Bplayer;
						//disable all button for futher input
						UI_object->Blank_out_Table(UI_object->get_Length());
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
						UI_object->is_that_an_SOS = false;
						previous_game_winner = UI_object->GameLogic_object->Bplayer;
						//disable all button for futher input
						UI_object->Blank_out_Table(UI_object->get_Length());
					}
				}
			}
			if (UI_object->GameLogic_object->GetCurrentPlayer() == UI_object->GameLogic_object->Rplayer)
			{
				//set label to button once pressed
				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->GameLogic_object->Get_Rplayer_Label());
				UI_object->GameLogic_object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->GameLogic_object->Get_Rplayer_Label();

				temp_Label = UI_object->GameLogic_object->Get_Rplayer_Label();
				if (temp_Label == "O")
				{
					//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
					//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);

					if (UI_object->is_that_an_SOS == true)
					{
						wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
						UI_object->is_that_an_SOS = false;
						previous_game_winner = UI_object->GameLogic_object->Rplayer;
						//disable all button for futher input
						UI_object->Blank_out_Table(UI_object->get_Length());
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
						UI_object->is_that_an_SOS = false;
						previous_game_winner = UI_object->GameLogic_object->Rplayer;
						//disable all button for futher input
						UI_object->Blank_out_Table(UI_object->get_Length());
					}
				}
			}
			if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)
			{
				wxMessageBox("Unbelievable ! It is a draw - Game Over");
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
			UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

			UI_object->GameLogic_object->SetNextPlayer();													//set next player
			UI_object->m_txt3->SetLabel(UI_object->GameLogic_object->GetCurrentPlayer() + " Player");				//update text to show whose turn

			evt.Skip();
		}
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Human" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Computer")
		{
			if (UI_object->GameLogic_object->GetCurrentPlayer() == UI_object->GameLogic_object->Bplayer)
			{
				//set label to button once pressed
				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->GameLogic_object->Get_Bplayer_Label());
				UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again
				
				UI_object->GameLogic_object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->GameLogic_object->Get_Bplayer_Label();

				temp_Label = UI_object->GameLogic_object->Get_Bplayer_Label();
				if (temp_Label == "O")
				{
					//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
					//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

					UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);

					if (UI_object->is_that_an_SOS == true)
					{
						wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
						UI_object->is_that_an_SOS = false;
						previous_game_winner = UI_object->GameLogic_object->Bplayer;
						//disable all button for futher input
						UI_object->Blank_out_Table(UI_object->get_Length());
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
						UI_object->is_that_an_SOS = false;
						previous_game_winner = UI_object->GameLogic_object->Bplayer;
						//disable all button for futher input
						UI_object->Blank_out_Table(UI_object->get_Length());
					}
				}

				//--------AI--------
				//set label to button once pressed
				UI_object->AI_object->Set_AI_label();
				temp_pair = UI_object->AI_object->AI_placement_on_2d_matrix(UI_object->GameLogic_object->Two_D_matrix);															//get a pair of cordinate x and y from AI
				x = temp_pair.first;
				y = temp_pair.second;

				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->AI_object->Get_AI_Label());
				UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

				UI_object->GameLogic_object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->AI_object->Get_AI_Label();

				temp_Label = UI_object->AI_object->Get_AI_Label();
				if (temp_Label == "O")
				{
					//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
					//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

					UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);

					if (UI_object->is_that_an_SOS == true)
					{
						wxMessageBox("The winner is Computer !!!- Game Over");
						UI_object->is_that_an_SOS = false;
						//previous_game_winner = UI_object->GameLogic_object->Bplayer;
						//disable all button for futher input
						UI_object->Blank_out_Table(UI_object->get_Length());
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						wxMessageBox("The winner is Computer !!!- Game Over");
						UI_object->is_that_an_SOS = false;
						//previous_game_winner = UI_object->GameLogic_object->Bplayer;
						//disable all button for futher input
						UI_object->Blank_out_Table(UI_object->get_Length());
					}
				}
				evt.Skip();
			}
			if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)
			{
				wxMessageBox("Unbelievable ! It is a draw - Game Over");
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
		}
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Computer" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Human")
		{
			//UI_object->m_txt3->SetLabel("Red Player");

			//set label to button once pressed
			UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->GameLogic_object->Get_Rplayer_Label());
			UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

			UI_object->GameLogic_object->already_fill_out++;
			//put that label to two dimentional vector
			UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->GameLogic_object->Get_Rplayer_Label();

			temp_Label = UI_object->GameLogic_object->Get_Rplayer_Label();
			if (temp_Label == "O")
			{
				//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
				//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

				UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);

				if (UI_object->is_that_an_SOS == true)
				{
					wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
					UI_object->is_that_an_SOS = false;
					previous_game_winner = UI_object->GameLogic_object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
			else
			{
				UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
				if (UI_object->is_that_an_SOS == true)
				{
					wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
					UI_object->is_that_an_SOS = false;
					previous_game_winner = UI_object->GameLogic_object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}

			//--------AI--------
			//set label to button once pressed
			UI_object->AI_object->Set_AI_label();
			temp_pair = UI_object->AI_object->AI_placement_on_2d_matrix(UI_object->GameLogic_object->Two_D_matrix);															//get a pair of cordinate x and y from AI
			x = temp_pair.first;
			y = temp_pair.second;

			UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->AI_object->Get_AI_Label());
			UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

			UI_object->GameLogic_object->already_fill_out++;
			//put that label to two dimentional vector
			UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->AI_object->Get_AI_Label();

			temp_Label = UI_object->AI_object->Get_AI_Label();
			if (temp_Label == "O")
			{
				//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
				//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

				UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);

				if (UI_object->is_that_an_SOS == true)
				{
					wxMessageBox("The winner is Computer !!!- Game Over");
					UI_object->is_that_an_SOS = false;
					//previous_game_winner = UI_object->GameLogic_object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
			else
			{
				UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
				if (UI_object->is_that_an_SOS == true)
				{
					wxMessageBox("The winner is Computer !!!- Game Over");
					UI_object->is_that_an_SOS = false;
					//previous_game_winner = UI_object->GameLogic_object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
			if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)
			{
				wxMessageBox("Unbelievable ! It is a draw - Game Over");
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
			evt.Skip();
		}
		
	}
	if (UI_object->GameLogic_object->GetGameMode() == "GeneralGame")
	{
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Human" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Human")
		{
			if (UI_object->GameLogic_object->already_fill_out != UI_object->GameLogic_object->total_buttons)
			{
				if (UI_object->GameLogic_object->GetCurrentPlayer() == UI_object->GameLogic_object->Bplayer)
				{
					//set label to button once pressed
					UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->GameLogic_object->Get_Bplayer_Label());
					UI_object->GameLogic_object->already_fill_out++;
					//put that label to two dimentional vector
					UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->GameLogic_object->Get_Bplayer_Label();

					temp_Label = UI_object->GameLogic_object->Get_Bplayer_Label();
					if (temp_Label == "O")
					{
						//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
						//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

						UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
						if (UI_object->is_that_an_SOS == true)
						{
							UI_object->GameLogic_object->Bplayer_SOS_counter++;
						}
					}
					else
					{
						UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
						if (UI_object->is_that_an_SOS == true)
						{
							UI_object->GameLogic_object->Bplayer_SOS_counter++;
						}
					}
				}
				if (UI_object->GameLogic_object->GetCurrentPlayer() == UI_object->GameLogic_object->Rplayer)
				{
					//set label to button once pressed
					UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->GameLogic_object->Get_Rplayer_Label());
					UI_object->GameLogic_object->already_fill_out++;
					//put that label to two dimentional vector
					UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->GameLogic_object->Get_Rplayer_Label();

					temp_Label = UI_object->GameLogic_object->Get_Rplayer_Label();
					if (temp_Label == "O")
					{
						//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
						//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

						UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
						if (UI_object->is_that_an_SOS == true)
						{
							UI_object->GameLogic_object->Rplayer_SOS_counter++;
						}
					}
					else
					{
						UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
						if (UI_object->is_that_an_SOS == true)
						{
							UI_object->GameLogic_object->Rplayer_SOS_counter++;
						}
					}
				}
			}
			if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)				//announce the winner when the board is filled up and end the game
			{
				if (UI_object->GameLogic_object->Bplayer_SOS_counter > UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("The winner is Blue Player !!!- Game Over");
					previous_game_winner = UI_object->GameLogic_object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else if (UI_object->GameLogic_object->Bplayer_SOS_counter < UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("The winner is Red Player !!!- Game Over");
					previous_game_winner = UI_object->GameLogic_object->Rplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else if (UI_object->GameLogic_object->Bplayer_SOS_counter = UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("Unbelievable ! It is a draw - Game Over");
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else
				{
					wxMessageBox("Unbelievable ! It is a draw - Game Over");
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
			evt.Skip();
		}
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Human" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Computer")
		{
			if (UI_object->GameLogic_object->already_fill_out != UI_object->GameLogic_object->total_buttons)
			{
				//---------------Human----------------
				//set label to button once pressed
				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->GameLogic_object->Get_Bplayer_Label());
				UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);					//Disable Button, preventing it being pressed again
				
				UI_object->GameLogic_object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->GameLogic_object->Get_Bplayer_Label();

				temp_Label = UI_object->GameLogic_object->Get_Bplayer_Label();
				if (temp_Label == "O")
				{
					//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
					//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

					UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->GameLogic_object->Bplayer_SOS_counter++;
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->GameLogic_object->Bplayer_SOS_counter++;
					}
				}
				
				//-----------AI----------------
				//set label to button once pressed
				UI_object->AI_object->Set_AI_label();
				temp_pair = UI_object->AI_object->AI_placement_on_2d_matrix(UI_object->GameLogic_object->Two_D_matrix);															//get a pair of cordinate x and y from AI
				
				if (temp_pair.first == -1 && temp_pair.second == -1)
				{
					if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)				//announce the winner when the board is filled up and end the game
					{
						if (UI_object->GameLogic_object->Bplayer_SOS_counter > UI_object->GameLogic_object->Rplayer_SOS_counter)
						{
							wxMessageBox("The winner is Human Player !!!- Game Over");
							previous_game_winner = UI_object->GameLogic_object->Bplayer;
							//disable all button for futher input
							UI_object->Blank_out_Table(UI_object->get_Length());
						}
						else if (UI_object->GameLogic_object->Bplayer_SOS_counter < UI_object->GameLogic_object->Rplayer_SOS_counter)
						{
							wxMessageBox("The winner is Computer Player !!!- Game Over");
							previous_game_winner = UI_object->GameLogic_object->Rplayer;
							//disable all button for futher input
							UI_object->Blank_out_Table(UI_object->get_Length());
						}
						else if (UI_object->GameLogic_object->Bplayer_SOS_counter = UI_object->GameLogic_object->Rplayer_SOS_counter)
						{
							wxMessageBox("Unbelievable ! It is a draw - Game Over");
							//disable all button for futher input
							UI_object->Blank_out_Table(UI_object->get_Length());
						}
						else
						{
							wxMessageBox("Unbelievable ! It is a draw - Game Over");
							//disable all button for futher input
							UI_object->Blank_out_Table(UI_object->get_Length());
						}
					}
					evt.Skip();
				}
				else
				{
					x = temp_pair.first;
					y = temp_pair.second;
				}
				
				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->AI_object->Get_AI_Label());
				UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again
				
				UI_object->GameLogic_object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->AI_object->Get_AI_Label();

				temp_Label = UI_object->AI_object->Get_AI_Label();
				if (temp_Label == "O")
				{
					//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
					//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

					UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->GameLogic_object->Rplayer_SOS_counter++;
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->GameLogic_object->Rplayer_SOS_counter++;
					}
				}
				
			}
			if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)				//announce the winner when the board is filled up and end the game
			{
				if (UI_object->GameLogic_object->Bplayer_SOS_counter > UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("The winner is Human Player !!!- Game Over");
					previous_game_winner = UI_object->GameLogic_object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else if (UI_object->GameLogic_object->Bplayer_SOS_counter < UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("The winner is Computer Player !!!- Game Over");
					previous_game_winner = UI_object->GameLogic_object->Rplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else if (UI_object->GameLogic_object->Bplayer_SOS_counter = UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("Unbelievable ! It is a draw - Game Over");
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else
				{
					wxMessageBox("Unbelievable ! It is a draw - Game Over");
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
		}
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Computer" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Human")
		{
			if (UI_object->GameLogic_object->already_fill_out != UI_object->GameLogic_object->total_buttons)
			{
				//---------------Human----------------
				//set label to button once pressed
				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->GameLogic_object->Get_Rplayer_Label());
				UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);					//Disable Button, preventing it being pressed again

				UI_object->GameLogic_object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->GameLogic_object->Get_Rplayer_Label();

				temp_Label = UI_object->GameLogic_object->Get_Rplayer_Label();
				if (temp_Label == "O")
				{
					//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
					//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

					UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->GameLogic_object->Rplayer_SOS_counter++;
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->GameLogic_object->Rplayer_SOS_counter++;
					}
				}

				//-----------AI----------------
				//set label to button once pressed
				UI_object->AI_object->Set_AI_label();
				temp_pair = UI_object->AI_object->AI_placement_on_2d_matrix(UI_object->GameLogic_object->Two_D_matrix);															//get a pair of cordinate x and y from AI

				if (temp_pair.first == -1 && temp_pair.second == -1)
				{
					if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)				//announce the winner when the board is filled up and end the game
					{
						if (UI_object->GameLogic_object->Bplayer_SOS_counter > UI_object->GameLogic_object->Rplayer_SOS_counter)
						{
							wxMessageBox("The winner is Computer Player !!!- Game Over");
							previous_game_winner = UI_object->GameLogic_object->Bplayer;
							//disable all button for futher input
							UI_object->Blank_out_Table(UI_object->get_Length());
						}
						else if (UI_object->GameLogic_object->Bplayer_SOS_counter < UI_object->GameLogic_object->Rplayer_SOS_counter)
						{
							wxMessageBox("The winner is Human Player !!!- Game Over");
							previous_game_winner = UI_object->GameLogic_object->Rplayer;
							//disable all button for futher input
							UI_object->Blank_out_Table(UI_object->get_Length());
						}
						else if (UI_object->GameLogic_object->Bplayer_SOS_counter = UI_object->GameLogic_object->Rplayer_SOS_counter)
						{
							wxMessageBox("Unbelievable ! It is a draw - Game Over");
							//disable all button for futher input
							UI_object->Blank_out_Table(UI_object->get_Length());
						}
						else
						{
							wxMessageBox("Unbelievable ! It is a draw - Game Over");
							//disable all button for futher input
							UI_object->Blank_out_Table(UI_object->get_Length());
						}
					}
					evt.Skip();
				}
				else
				{
					x = temp_pair.first;
					y = temp_pair.second;
				}

				UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->AI_object->Get_AI_Label());
				UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

				UI_object->GameLogic_object->already_fill_out++;
				//put that label to two dimentional vector
				UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->AI_object->Get_AI_Label();

				temp_Label = UI_object->AI_object->Get_AI_Label();
				if (temp_Label == "O")
				{
					//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
					//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

					UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->GameLogic_object->Bplayer_SOS_counter++;
					}
				}
				else
				{
					UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
					if (UI_object->is_that_an_SOS == true)
					{
						UI_object->GameLogic_object->Bplayer_SOS_counter++;
					}
				}

			}
			if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)				//announce the winner when the board is filled up and end the game
			{
				if (UI_object->GameLogic_object->Bplayer_SOS_counter > UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("The winner is Computer Player !!!- Game Over");
					previous_game_winner = UI_object->GameLogic_object->Bplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else if (UI_object->GameLogic_object->Bplayer_SOS_counter < UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("The winner is Human Player !!!- Game Over");
					previous_game_winner = UI_object->GameLogic_object->Rplayer;
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else if (UI_object->GameLogic_object->Bplayer_SOS_counter = UI_object->GameLogic_object->Rplayer_SOS_counter)
				{
					wxMessageBox("Unbelievable ! It is a draw - Game Over");
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
				else
				{
					wxMessageBox("Unbelievable ! It is a draw - Game Over");
					//disable all button for futher input
					UI_object->Blank_out_Table(UI_object->get_Length());
				}
			}
		}
	}
}

void cMain::AI_OnButtonClicked(wxCommandEvent& evt)
{
	if (UI_object->GameLogic_object->GetGameMode() == "SimpleGame")
	{
		//--------AI--------
		string temp_Label;
		pair<int, int> temp_pair;
		int x, y;
		//set label to button once pressed
		UI_object->AI_object->Set_AI_label();
		temp_pair = UI_object->AI_object->AI_placement_on_2d_matrix(UI_object->GameLogic_object->Two_D_matrix);															//get a pair of cordinate x and y from AI
		x = temp_pair.first;
		y = temp_pair.second;

		UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->AI_object->Get_AI_Label());
		UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

		UI_object->GameLogic_object->already_fill_out++;
		//put that label to two dimentional vector
		UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->AI_object->Get_AI_Label();

		temp_Label = UI_object->AI_object->Get_AI_Label();
		if (temp_Label == "O")
		{
			//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
			//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

			UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);

			if (UI_object->is_that_an_SOS == true)
			{
				wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
				UI_object->is_that_an_SOS = false;
				//previous_game_winner = UI_object->GameLogic_object->Bplayer;
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
		}
		else
		{
			UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
			if (UI_object->is_that_an_SOS == true)
			{
				wxMessageBox("The winner is " + UI_object->GameLogic_object->GetCurrentPlayer() + " !!!- Game Over");
				UI_object->is_that_an_SOS = false;
				//previous_game_winner = UI_object->GameLogic_object->Bplayer;
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
				evt.Skip();
			}
		}
		
		if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)
		{
			wxMessageBox("Unbelievable ! It is a draw - Game Over");
			//disable all button for futher input
			UI_object->Blank_out_Table(UI_object->get_Length());
		}
		UI_object->GameLogic_object->SetNextPlayer();
		UI_object->m_txt3->SetLabel(UI_object->GameLogic_object->GetCurrentPlayer() + " Player");
	}
	if (UI_object->GameLogic_object->GetGameMode() == "GeneralGame")
	{
		//--------AI--------
		string temp_Label;
		pair<int, int> temp_pair;
		int x, y;
		//set label to button once pressed
		UI_object->AI_object->Set_AI_label();
		temp_pair = UI_object->AI_object->AI_placement_on_2d_matrix(UI_object->GameLogic_object->Two_D_matrix);															//get a pair of cordinate x and y from AI
		x = temp_pair.first;
		y = temp_pair.second;

		UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->AI_object->Get_AI_Label());
		UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

		UI_object->GameLogic_object->already_fill_out++;
		//put that label to two dimentional vector
		UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->AI_object->Get_AI_Label();

		temp_Label = UI_object->AI_object->Get_AI_Label();
		if (temp_Label == "O")
		{
			//UI_object->GameLogic_object->Vector_of_Adjacent_elements = UI_object->GameLogic_object->getAdjacent(UI_object->GameLogic_object->Two_D_matrix, x, y);
			//UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Vector_of_Adjacent_elements);

			UI_object->is_that_an_SOS = UI_object->GameLogic_object->O_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);

			if (UI_object->is_that_an_SOS == true)
			{
				if (UI_object->GameLogic_object->GetCurrentPlayer() == UI_object->GameLogic_object->Bplayer)
				{
					UI_object->GameLogic_object->Bplayer_SOS_counter++;
				}
				else
				{
					UI_object->GameLogic_object->Rplayer_SOS_counter++;
				}
			}
		}
		else
		{
			UI_object->is_that_an_SOS = UI_object->GameLogic_object->S_scenerio_checker(UI_object->GameLogic_object->Two_D_matrix, UI_object->get_Length(), UI_object->get_Length(), x, y);
			if (UI_object->is_that_an_SOS == true)
			{
				if (UI_object->GameLogic_object->GetCurrentPlayer() == UI_object->GameLogic_object->Bplayer)
				{
					UI_object->GameLogic_object->Bplayer_SOS_counter++;
				}
				else
				{
					UI_object->GameLogic_object->Rplayer_SOS_counter++;
				}
			}
		}

		if (UI_object->GameLogic_object->already_fill_out == UI_object->GameLogic_object->total_buttons)
		{
			if (UI_object->GameLogic_object->Bplayer_SOS_counter > UI_object->GameLogic_object->Rplayer_SOS_counter)
			{
				wxMessageBox("The winner is Blue Player !!!- Game Over");
				previous_game_winner = UI_object->GameLogic_object->Bplayer;
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
			else if (UI_object->GameLogic_object->Bplayer_SOS_counter < UI_object->GameLogic_object->Rplayer_SOS_counter)
			{
				wxMessageBox("The winner is Red Player !!!- Game Over");
				previous_game_winner = UI_object->GameLogic_object->Rplayer;
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
			else if (UI_object->GameLogic_object->Bplayer_SOS_counter = UI_object->GameLogic_object->Rplayer_SOS_counter)
			{
				wxMessageBox("Unbelievable ! It is a draw - Game Over");
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
			else
			{
				wxMessageBox("Unbelievable ! It is a draw - Game Over");
				//disable all button for futher input
				UI_object->Blank_out_Table(UI_object->get_Length());
			}
		}
		UI_object->GameLogic_object->SetNextPlayer();
		UI_object->m_txt3->SetLabel(UI_object->GameLogic_object->GetCurrentPlayer() + " Player");
	}
}

void cMain::BoardSize(wxCommandEvent& evt)
{
	UI_object->length_string = UI_object->m_txt1->GetValue();
	UI_object->m_txt1->Clear();
	stringstream StringToInt(UI_object->length_string);                                                                                  	// GameLogic_object from the class stringstream
	StringToInt >> UI_object->length_int;
	UI_object->set_Length(UI_object->length_int);
	UI_object->AI_object->AI_length = UI_object->length_int; //infrom AI the length of the board
	
	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	InitializeTable(font, UI_object->get_Length());

	//initialize Two_D_matrix size with length from user input
	vector<vector<string>> temp(UI_object->get_Length(), vector<string>(UI_object->get_Length(), " "));
	UI_object->GameLogic_object->Two_D_matrix = temp;

	UI_object->GameLogic_object->total_buttons = UI_object->length_int * UI_object->length_int;							//initialize value for total_buttons which is a counter for general game
	
	if (UI_object->GameLogic_object->GetGameMode() == "SimpleGame")
	{
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Computer" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Human")
		{
			//--------AI--------
			string temp_Label;
			pair<int, int> temp_pair;
			int x, y;
			//set label to button once pressed
			UI_object->AI_object->Set_AI_label();
			temp_pair = UI_object->AI_object->AI_placement_on_2d_matrix(UI_object->GameLogic_object->Two_D_matrix);															//get a pair of cordinate x and y from AI
			x = temp_pair.first;
			y = temp_pair.second;

			UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->AI_object->Get_AI_Label());
			UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

			UI_object->GameLogic_object->already_fill_out++;
			//put that label to two dimentional vector
			UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->AI_object->Get_AI_Label();

			UI_object->m_txt3->SetLabel("Red Player");
		}
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Computer" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Computer")
		{
			UI_object->AI_move = new wxButton(this, 3003, "AI Move", wxPoint(30, 270), wxSize(70, 25));
		}
	}
	if (UI_object->GameLogic_object->GetGameMode() == "GeneralGame")
	{
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Computer" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Human")
		{
			//-----------AI----------------
			string temp_Label;
			pair<int, int> temp_pair;
			int x, y;
			//set label to button once pressed
			UI_object->AI_object->Set_AI_label();
			temp_pair = UI_object->AI_object->AI_placement_on_2d_matrix(UI_object->GameLogic_object->Two_D_matrix);
			x = temp_pair.first;
			y = temp_pair.second;

			UI_object->btn[y * UI_object->get_Length() + x]->SetLabel(UI_object->AI_object->Get_AI_Label());
			UI_object->btn[y * UI_object->get_Length() + x]->Enable(false);								//Disable Button, preventing it being pressed again

			UI_object->GameLogic_object->already_fill_out++;
			//put that label to two dimentional vector
			UI_object->GameLogic_object->Two_D_matrix[x][y] = UI_object->AI_object->Get_AI_Label();

			UI_object->m_txt3->SetLabel("Red Player");
		}
		if (UI_object->GameLogic_object->Get_Bplayer_Human_or_AI() == "Computer" && UI_object->GameLogic_object->Get_Rplayer_Human_or_AI() == "Computer")
		{
			UI_object->AI_move = new wxButton(this, 3003, "AI Move", wxPoint(30, 270), wxSize(70, 25));
		}
	}
}

void cMain::Simple_game_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->SetGameMode(UI_object->GameLogic_object->simple_Game);
}

void cMain::General_game_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->SetGameMode(UI_object->GameLogic_object->general_Game);
}
void cMain::Bplayer_S_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->Set_Bplayer_Label(UI_object->GameLogic_object->s);
}
void cMain::Bplayer_O_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->Set_Bplayer_Label(UI_object->GameLogic_object->o);
}
void cMain::Rplayer_S_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->Set_Rplayer_Label(UI_object->GameLogic_object->s);
}
void cMain::Rplayer_O_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->Set_Rplayer_Label(UI_object->GameLogic_object->o);
}
void cMain::Restart(wxCommandEvent& evt)
{
	//remove last game component
	bgPanel->Destroy();
	UI_object->m_txt1->Destroy();

	bgPanel = new wxPanel(this, wxID_ANY, wxPoint(170, 70), wxSize(200, 200));
	
	UI_object = new UI;
	UI_object -> GameLogic_object->SetCurrentPlayer(previous_game_winner);
	
	InitializeComponent();
}

void cMain::Bplayer_Human_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->Set_Bplayer_Human_or_AI("Human");
}

void cMain::Bplayer_AI_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->Set_Bplayer_Human_or_AI("Computer");
}

void cMain::Rplayer_Human_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->Set_Rplayer_Human_or_AI("Human");
}

void cMain::Rplayer_AI_Checked(wxCommandEvent& evt)
{
	UI_object->GameLogic_object->Set_Rplayer_Human_or_AI("Computer");
}