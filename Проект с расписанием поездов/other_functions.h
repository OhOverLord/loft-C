#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

using namespace std;

int read_file(vector<PassengerTrain> & trains)
{
    ifstream fin("Trains.txt");
    if ( !fin )
    {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    while (!fin.eof())
    {
        int train_number;
        string destination, departure_time, arrival_time;
        fin >> train_number >> destination >> departure_time >> arrival_time;
        PassengerTrain t(train_number, destination, departure_time, arrival_time);
        trains.push_back(t);
    }
    fin.close();
}

struct less_than_key
{
    inline bool operator() (const PassengerTrain& train_one,
                            const PassengerTrain& train_two)
    {
        if(train_one.departure_time_vec[0] != train_two.departure_time_vec[0])
            return (train_one.departure_time_vec[0] < train_two.departure_time_vec[0]);
        else
            return (train_one.departure_time_vec[1] < train_two.departure_time_vec[1]);
    }
};

void train_number_output(vector<PassengerTrain> & trains)
{
    int num, sch = 0;
    cout << "Train number - ?: ";
    cin >> num;
    for(int j = 0; j < trains.size(); j++)
    {
        if(trains[j].train_number_output(num))
        {
            trains[j].output_info();
            sch++;
        }
    }
    if(sch == 0)
    {
        cout << "There are no trains with this number" << endl;
    }
}

void clear_file(char file[20])
{
    ofstream write_to_file(file);
    write_to_file << "";
    write_to_file.close();
}

void output_all(vector<PassengerTrain> & trains)
{
    for(int j = 0; j < trains.size(); j++)
    {
        trains[j].output_info();
    }
}

void sort_output_all(vector<PassengerTrain> & trains)
{
    sort(trains.begin(), trains.end(), less_than_key());
    for(int j = 0; j < trains.size(); j++)
    {
        trains[j].output_info();
    }
}

void stations_sort(vector<PassengerTrain> & trains)
{
    clear_file("trains_info.txt");
    string station;
    cout << "Station - ?: ";
    cin >> station;
    int sch = 0;
    for(int i = 0; i < trains.size(); i++)
    {
        trains[i].read_stations();
        if(trains[i].stations_sort(station))
        {
            trains[i].write_to_file();
            sch++;
        }
    }
    if(sch == 0)
    {
        cout << "There are no such trains" << endl;
    }
    else
    {
        cout << "Look in the file trains_info.txt";
    }
}

void output_stations(vector<PassengerTrain> & trains)
{
    for(int j = 0; j < trains.size(); j++)
    {
        trains[j].read_stations();
        trains[j].output_stations();
    }
}

int menu(vector<PassengerTrain> & trains)
{
    int num;
    cout << "1) Find a train by number" << endl;
    cout << "2) All trains bound for destination" << endl;
    cout << "3) Sort by departure time" << endl;
    cout << "4) Display all train stations" << endl;
    cout << "5) Exit" << endl;
    cin >> num;
    cout << endl;
    switch(num)
    {
    case 1:
        train_number_output(trains);
        break;
    case 2:
        stations_sort(trains);
        break;
    case 3:
        sort_output_all(trains);
        break;
    case 4:
        output_stations(trains);
        break;
    case 5:
        return 0;
        break;
    }
}

#endif
