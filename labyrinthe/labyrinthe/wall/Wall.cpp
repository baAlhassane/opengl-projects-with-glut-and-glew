#include "Wall.h"
#include <fstream>
#include <iostream>
#include <string>

void Wall::loadFile(const char* fileName) {
    std::ifstream file(fileName, std::ios::in);

    int num_columns = 0;
    int num_lines = 0;

    std::cout << "When opening file..." << std::endl;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1); // Enlève les espaces et caractères invisibles de la fin
            std::cout << "  aaa" << line << "aaaa  " << std::endl;
            num_columns = line.length();  // Largeur (nombre de caractères dans une ligne)
            ++num_lines;  // Hauteur (nombre de lignes)
        }
        heigth = num_lines;  // Hauteur = nombre de lignes
        width = num_columns;  // Largeur = nombre de caractères dans la dernière ligne
    }
    file.close();

    // Ré-ouvrir le fichier pour lire les données dans `data`
    std::ifstream f(fileName, std::ios::in);
    if (f.is_open()) {
        data = new char* [heigth];  // Allouer selon les dimensions correctes
        for (int i = 0; i < heigth; i++) {
            data[i] = new char[width];  // Chaque ligne a `width` colonnes
        }

        // Initialisation de `data` avec des valeurs par défaut
        for (int i = 0; i < heigth; i++) {
            for (int j = 0; j < width; j++) {
                data[i][j] = '0';  // Par défaut, on remplit avec '0'
            }
        }

        // Lire les données du fichier
        std::cout << "\nData[i] in lecture file\n";
        for (int i = 0; i < heigth; i++) {
            matrice.resize(heigth);
            for (int j = 0; j < width; j++) {
               
                f >> data[i][j];  // Lire chaque caractère dans le tableau
                matrice[i].push_back(data[i][j]);
            }
        }
    }
    f.close();
}

Wall::~Wall() {
    // Libération de la mémoire allouée dynamiquement
    for (int i = 0; i < heigth; i++) {
        delete[] data[i];
    }
    delete[] data;
}

int Wall::getHeight() const {
    return heigth;
}

int Wall::getWidth() const {
    return width;
}

char** Wall::getData() {
    return data;
}
//std::vector<std::vector<char >> Wall::matrice;


std::vector<std::vector<char>>Wall::getDatav() const{
 
    return matrice;
}
























//#include "Wall.h"
//#include<fstream>
//#include<iostream>
//#include<string>
//
//void Wall::loadFile(const char* fileName) {
//
//	std::ifstream file(fileName, std::ios::in);
//	//file.open(fileName);
//	int num_columns = 0;
//	int num_lines = 0;
//	std::cout << " when opening file"<< std::endl;
//	if (file.is_open()) {
//		//std::cout << "error when opening file" <<std::endl;
//		std::string line;
//		while (std::getline(file, line)) {
//			std::cout << "  aaa" << line << "aaaa  " << std::endl;
//			num_columns = line.length();
//			++num_lines;	
//		}
//		heigth = num_lines;
//		width = num_columns;
//
//	
//		
//	}
//	file.close();
//
//
//	std::ifstream f(fileName, std::ios::in);
//
//	if (f.is_open()) {
//		data = new char* [width];
//
//		for (int i = 0; i < width; i++) {
//			data[i] = new char[heigth];
//		}
//		for (int i = 0; i < width; i++) {
//			for (int j = 0; j < heigth; j++) {
//				data[i][j] = '0';
//			}
//		}
//
//		//dddd
//		// read file withe the data
//		std::cout << "\n data[i] in lecture file\n ";
//		for (int i = 0; i < width; i++) {
//			f >> data[i];
//			
//			std::cout << data[i] << "   ligne -0" << i << std::endl;
//			//for (int j = 0; j < heigth; j++) {
//			//	f >> data[i][j];
//			//}
//		}
//	}
//	f.close();
//
//	
//}
//
//
//
//
//
//	Wall::~Wall(){
//		for (int i = 0; i < width; i++) {
//				delete [] data[i];
//			
//		}
//
//		delete[] data;
//
//	}
//
//	
//
//
//
//	int Wall::getHeight() const {
//		return heigth;
//	}
//	int Wall::getWidth()  const {
//		return width;
//	}
//
//	char** Wall::getData() {
//
//		return data;
//	}


/*
	Wall::Wall(const Wall& wall) {
		//data = nullptr;
		width = wall.width;
		heigth = wall.heigth;

		data = new char* [width];

		for (int i = 0; i < wall.width; i++) {
			data[i] = new char[heigth];
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < heigth; j++) {
				data[i][j] = wall.data[i][j];
			}
		}

		
	}
	*/