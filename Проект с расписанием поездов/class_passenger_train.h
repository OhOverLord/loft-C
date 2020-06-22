#ifndef CLASS_PASSENGER_TRAIN_H
#define CLASS_PASSENGER_TRAIN_H

using namespace std;
class Train
{
private:
    string departure_time;
    string arrival_time;
    vector<int> arrival_time_vec;
    string destination;

public:
    vector<int> departure_time_vec;
    int train_number;

    Train(int train_number, string destination,
          string departure_time, string arrival_time)
    {
        this->train_number = train_number;
        this->destination = destination;
        this->departure_time = departure_time;
        this->arrival_time = arrival_time;
    }

    void time_splitting()
    {
        char * pch = strtok(const_cast <char*> (departure_time.c_str()), ":");
        while (pch != NULL)
        {
            departure_time_vec.push_back(atoi(pch));
            pch = strtok(NULL, ":");
        }
    }

    void output_info()
    {
        cout << "Train number: ";
        cout << this->train_number << endl;
        cout << "Departure time: ";
        cout << this->departure_time << endl;
        cout << "Arrival time: ";
        cout << this->arrival_time << endl;
        cout << "Destination: ";
        cout << this->destination << endl;
        cout << "/--------------/" << endl;
    }

    void write_to_file()
    {
        ofstream write_to_file("trains_info.txt",ios::app);
        write_to_file << "/--------------/" << endl;
        write_to_file << "Train number: ";
        write_to_file << this->train_number << endl;
        write_to_file << "Departure time: " << endl;
        write_to_file << this->departure_time << endl;
        write_to_file << "Arrival time: " << endl;
        write_to_file << this->arrival_time << endl;
        write_to_file << "Destination: " << endl;
        write_to_file << this->destination << endl;
        write_to_file << "/--------------/" << endl;
        write_to_file.close();
    }

    bool train_number_output(int num)
    {
        if(num == this->train_number)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class PassengerTrain : public Train
{
public:
    int driving_time;
    vector<string> stations;

    PassengerTrain(int train_number,
                   string destination,
                   string departure_time,
                   string arrival_time) : Train(
                           train_number,
                           destination,
                           departure_time,
                           arrival_time) {}

    int read_stations()
    {
        ifstream fin("Passengers trains stations.txt");
        if ( !fin )
        {
            cout << "Ошибка открытия файла." << endl;
            return 0;
        }
        while (!fin.eof())
        {
            string str;
            getline(fin, str);
            char * pch = strtok(const_cast <char*> (str.c_str()), "/");
            if(this->train_number == atoi(pch))
            {
                while (pch != NULL)
                {
                    stations.push_back(pch);
                    pch = strtok(NULL, "/");
                }
            }
        }
        fin.close();
    }

    bool stations_sort(string station)
    {
        for(int i = 0; i < stations.size(); i++)
        {
            if(station == stations[i])
            {
                return true;
            }
        }
    }

    void output_stations()
    {
        cout << endl;
        cout << "Train number: ";
        cout << stations[0] << endl;
        cout << "Stations: ";
        for(int i = 1; i < stations.size(); i++)
        {
            cout << stations[i] << ", ";
        }
        cout << endl;
    }
};

#endif // CLASS_PASSENGER_H
