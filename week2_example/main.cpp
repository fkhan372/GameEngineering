#include <iostream>

#include "NoCommandDemo.h"
#include "CommandDemo.h"
#include "Unit.h"
#include "Physics.h"
#include "Achievements.h"
#include "Robots.h"
#include "FileController.h"
#include "StackAllocator.h"
#include "ObjectPool.h"
#include "ResourceA.h"
#include "Asset.h"
#include "AssetController.h"

int main()
{
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~START OF LAB 1
	// NUMBER 1
	/*NoCommandDemo* ncd = new NoCommandDemo();
	std::cout << "No Commands:\n";
	ncd->HandleInput("X");
	ncd->HandleInput("Y");
	ncd->HandleInput("A");
	ncd->HandleInput("B");
	delete ncd;*/

	// NUMBER 2
	/*CommandDemo* cd = new CommandDemo();
	std::cout << "\nCommands:\n";
	cd->HandleInput("X");
	cd->HandleInput("Y");
	cd->HandleInput("A");
	cd->HandleInput("B");
	delete cd;*/

	// NUMBER 3
	/*CommandDemo* cd = new CommandDemo();
	std::cout << "\nUndo Commands:\n";
	cd->HandleInput("W");
	cd->HandleInput("A");
	cd->HandleInput("S");
	cd->HandleInput("D");
	cd->Undo();
	cd->Undo();
	cd->Undo();
	cd->Undo();
	delete cd;*/

	// NUMBER 4
	/*Achievements* achievements = new Achievements();
	Physics* physics = new Physics();
	Unit* unit = new Unit();

	physics->GetEventFalling()->AddObserver(achievements);
	unit->MoveTo(0, 1);
	physics->Update(unit);
	unit->MoveTo(0, 0);
	physics->Update(unit);
	unit->MoveTo(0, -1);
	physics->Update(unit);

	delete unit;
	delete physics;
	delete achievements;*/

	// NUMBER 5
	/*Achievements* achievements = new Achievements();
	Unit* unit = new Unit();

	Physics::Instance().GetEventFalling()->AddObserver(achievements);
	unit->MoveTo(0, 1);
	unit->MoveTo(0, 0);
	unit->MoveTo(0, -1);
	Physics::Instance().Update(unit);

	delete unit;
	delete achievements;*/

	// NUMBER 6
	/*InheritanceRobot* ir = new InheritanceRobot();
	std::cout << "Inheritance Robot\n";
	ir->Grab();
	ir->Walk();

	CompositionRobot* cr = new CompositionRobot();
	std::cout << "\nComposition Robot\n";
	cr->Grab();
	cr->Walk();*/

	// NUMBER 7
	/*Unit* unit = new Unit();
	float count = 0.0f;
	while (count < 10)
	{
		unit->Update();
		unit->MoveTo((int)count, 10);
		std::cout << unit->GetCachedData().str() << "\n";
		count += 0.333f;
	}

	delete unit;*/

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~START OF LAB 2
	// NUMBER 1
	/*FileController* fc = &FileController::Instance();
	cout << fc->GetCurDirectory() << endl;
	int fs = fc->GetFileSize("FileController.cpp");
	unsigned char* buffer = new unsigned char[fs];
	if (fc->ReadFile("FileController.cpp", buffer, fs))
	{
		cout << "File read operation successful." << endl;
	}

	delete[] buffer;*/

	// NUMBER 2
	/*FileController* fc = &FileController::Instance();
	cout << fc->GetCurDirectory() << endl;
	int fs = fc->GetFileSize("FileController.cpp");
	unsigned char* buffer = new unsigned char[fs];
	fc->ReadFileAsync("FileController.cpp", buffer, fs);
	while (!fc->GetFileReadDone())
	{
		cout << "Thread Running..." << std::endl;
	}
	if (fc->GetFileReadSuccess())
	{
		cout << "File size: " << fs << endl;
	}
	else
	{
		cout << "File read operation unsuccessful." << endl;
	}

	delete[] buffer;*/

	// NUMBER 3
	//FileController* fc = &FileController::Instance();
	//StackAllocator* sa = new StackAllocator();
	//sa->AllocateStack(100); // Allocate 100 bytes on the heap

	//int fs1 = fc->GetFileSize("File1.txt");
	//unsigned char* file1 = sa->GetMemory(fs1);
	//fc->ReadFile("File1.txt", file1, fs1);
	//cout << file1 << endl;

	//int fs2 = fc->GetFileSize("File2.txt");
	//unsigned char* file2 = sa->GetMemory(fs2);
	//fc->ReadFile("File2.txt", file2, fs2);
	//sa->Mark();
	//cout << file2 << endl;

	//int fs3 = fc->GetFileSize("File3.txt");
	//unsigned char* file3 = sa->GetMemory(fs3);
	//fc->ReadFile("File3.txt", file3, fs3);
	//cout << file3 << endl;

	//cout << "Bytes used: " << sa->GetBytesUsed() << " Content: " << file1 << endl;
	//sa->FreeToMarker();
	//cout << file1 << endl;
	//cout << "Bytes used: " << sa->GetBytesUsed() << " Content: " << file1 << endl;

	//delete sa;

	// NUMBER 4
	/*ObjectPool<Resource>* objP = new ObjectPool<Resource>();
	Resource* r1 = objP->GetResource();
	r1->AssignNonDefaultValues();

	ofstream writeStream("resource.bin", ios::out | ios::binary);
	r1->Serialize(writeStream);
	writeStream.close();
	cout << "r1 values: ";
	r1->ToString();

	Resource* r2 = objP->GetResource();
	ifstream readStream("resource.bin", ios::in | ios::binary);
	r2->Deserialize(readStream);
	readStream.close();
	cout << "r2 values: ";
	r1->ToString();

	delete objP;*/

	// NUMBER 5
	/*Resource::Pool = new ObjectPool<Resource>();
	Resource* r1 = Resource::Pool->GetResource();
	r1->AssignNonDefaultValues();

	ofstream writeStream("resource.bin", ios::out | ios::binary);
	r1->Serialize(writeStream);
	writeStream.close();
	cout << "r1 values: ";
	r1->ToString();

	Resource* r2 = Resource::Pool->GetResource();
	ifstream readStream("resource.bin", ios::in | ios::binary);
	r2->Deserialize(readStream);
	readStream.close();
	cout << "r2 values: ";
	r1->ToString();

	delete Resource::Pool;*/

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~START OF LAB 3
	// NUMBER 1
	AssetController::Instance().Initialize(10000000);
	Asset* asset = AssetController::Instance().GetAsset("emoji.jpg");
	cout << "Bytes used by image.bmp: " << AssetController::Stack->GetBytesUsed() << endl;

}