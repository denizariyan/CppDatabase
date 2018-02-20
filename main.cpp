# include <iostream>
# include <string >
# include <fstream>
# include <windows.h>
# include <iomanip>
using namespace std ;
void name () ;
void ID () ;
void showall();

int main () {
	system ("cls") ;
	system ("color 0F") ;
	int uinput ;
	cout << "1 for new data" << endl;
	cout << "2 for seaching by ID" << endl;
	cout << "3 show all the datas" << endl;
	cout << "4 Exit" << endl;
        cin >> uinput ;
	if (uinput == 1) {
		name () ;
	}
	else if (uinput == 2) {
		ID () ;
	}
	else if (uinput == 3) {
		showall();
	} else if(uinput == 4) {
		exit(EXIT_SUCCESS);
	} else {
		cout<<"You made a bad input please try again"<<endl;
		system("pause");
		main();
	}

}

void name() {
	system ("cls") ;
	string name , Surname  ;
	ofstream worker ("students.txt",ios ::app);
	int ID;
	cout << "Name : ";
	cin >> name ;
	cout << "Surnmae : " ;
	cin >> Surname ;
	cout << "ID : " ;
	cin >> ID ;
	if(cin.fail()) {
	cin.clear(); // fix cin
    cin.ignore(80, '\n');  // remove what broke it from the buffer
		cout<<"Bad input returning to menu"<<endl;
		system("pause");
		main();
	}

	worker << name << " " << Surname << " " << ID << endl;
	worker.close () ;
	cin.get () ;
	main () ;
}

void ID() {
	ifstream worker ("students.txt") ;
	int ID , str ;
	string name , Surname  ;
	cout << "Enter ID : " ;
	cin >> str ;

	while (worker >> name >> Surname >> ID) {
		if (str == ID) {
			system ("cls") ;
			cout << "NAME"<<" "<<"SURNAME"<<" "<<"ID" << endl;
			cout << name << " " << Surname << " "  << ID << endl; 
			cin.get();
			break;
		}

		else if (!(str == ID)) {
			system ("cls") ;
			cout << "Not Found !" << endl;
		}
	}
	system ("pause") ;
	main () ;
}

void showall() {
	char c;
   FILE *ffile;
   ffile = fopen("students.txt","r");
   if( ffile == NULL ) {
      perror("Error opening the file, check spelling and be sure to put the file in the same directory as the program!\n");
      exit(1);
   }
 cout << "NAME"<<" "<<"SURNAME"<<" "<<"ID" << endl;
   while((c = fgetc(ffile)) != EOF) {
      printf("%c",c);
   }
   fclose(ffile);
system ("pause") ;
main () ;
}
