#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

 
//Stupac 1,4,12 (0,3,11) -> iteratori
class Measures{
	private:
		std::vector<double> vektor_double;
		std::vector<double> prazni;
		std::string line,u_q,coolant,stator_winding,u_d,stator_tooth,motor_speed,i_d,i_q,pm,stator_yoke,ambient,torque,profile_id;
	public:
		std::vector<std::string> stupac1;
		std::vector<std::string> stupac4;
		std::vector<std::string> stupac12;
		void spremi(){
			std::ifstream file ("measures_v2.csv");
			
			while(std::getline(file, line)){
				std::stringstream linestream(line);
				std::getline(linestream, u_q, ',');
				std::getline(linestream, coolant, ',');
				std::getline(linestream, stator_winding, ',');
				std::getline(linestream, u_d, ',');
				std::getline(linestream, stator_tooth, ',');
				std::getline(linestream,motor_speed, ',');
				std::getline(linestream,i_d, ',');
				std::getline(linestream,i_q, ',');
				std::getline(linestream,pm, ',');
				std::getline(linestream,stator_yoke, ',');
				std::getline(linestream,ambient, ',');
				std::getline(linestream,torque, ',');
				std::getline(linestream,profile_id, ',');
				stupac1.push_back(u_q);
				stupac4.push_back(u_d);
				stupac12.push_back(torque);
			}
		}
			void ispisNzapisaMAX(std::vector<std::string>& vektor, int n=0){
				vektor_double.clear();
				std::transform(vektor.begin()+1, vektor.end(), std::back_inserter(vektor_double),[](const std::string& str) { return std::stod(str); });
				std::sort(vektor_double.begin(),vektor_double.end(),std::greater<>());

				if(n==0){
					std::cout << std::fixed << std::setprecision(12) <<vektor_double[0]<<std::endl;
				}
				else if(n>0){
					for(int i=0; i<n;i++){
						std::cout << std::fixed << std::setprecision(12) <<vektor_double[i]<<std::endl;
					}
				}
				else{
					std::cout<<"Neispravan broj!";
				}			
			}

			void ispisNzapisaMIN(std::vector<std::string>& vektor, int n=0){
				vektor_double.clear();
				std::transform(vektor.begin()+1, vektor.end(), std::back_inserter(vektor_double),[](const std::string& str) { return std::stod(str); });
				std::sort(vektor_double.begin(),vektor_double.end(),std::less<>());

				if(n==0){
					std::cout << std::fixed << std::setprecision(12) <<vektor_double[0]<<std::endl;
				}
				else if(n>0){
					for(int i=0; i<n;i++){
						std::cout << std::fixed << std::setprecision(12) <<vektor_double[i]<<std::endl;
					}
				}
				else{
					std::cout<<"Neispravan broj!";
				}			
			}
			
			void pronadiNzapisa(std::vector<std::string>& vektor,std::vector<double>& vrijednosti){
				vektor_double.clear();
				std::transform(vektor.begin()+1, vektor.end(), std::back_inserter(vektor_double),[](const std::string& str) { return std::stod(str); });
				std::sort(vektor_double.begin(),vektor_double.end(), std::less<>());
				std::sort(vrijednosti.begin(), vrijednosti.end(),std::less<>());

				for(auto i : vrijednosti){
					if(std::binary_search(vektor_double.begin(), vektor_double.end(), i)){
						std::cout  << std::fixed << std::setprecision(12) <<"Pronadena je vrijednost: "<<i<<std::endl;
					}
					else{
						std::cout << std::fixed << std::setprecision(12) << "Vrijednost " << i << "nije pronadena"<<std::endl;
					}
				}
			}
			
			void obrisiNzapisa(std::vector<std::string>& vektor,std::vector<double>& vrijednosti){
				vektor_double.clear();
				std::transform(vektor.begin()+1, vektor.end(), std::back_inserter(vektor_double),[](const std::string& str) { return std::stod(str); });
				for (int i=0;i<vrijednosti.size();i++){
    				auto iterator = std::remove(vektor_double.begin(), vektor_double.end(), vrijednosti[i]);
    				vektor_double.erase(iterator, vektor_double.end());
				}
			}
			void dodajNzapisa(std::vector<std::string>& vektor,std::vector<double>& vrijednosti){
				vektor_double.clear();
				std::transform(vektor.begin()+1, vektor.end(), std::back_inserter(vektor_double),[](const std::string& str) { return std::stod(str); });
				for(int i =0;i<vrijednosti.size();i++)
					vektor_double.push_back(vrijednosti[i]);
				
			}
		

};
int main()
{
 	Measures measures;
	std::vector<double> unesi = {10.001023, 101.20002, -1.023};
	std::vector<double> pretraga = {24.43513272236875, 24.431000809582198};
	measures.spremi();
	auto start = std::chrono::high_resolution_clock::now();
	measures.ispisNzapisaMAX(measures.stupac1);
	//measures.ispisNzapisaMIN(measures.stupac1);
	//measures.pronadiNzapisa(measures.stupac1, pretraga);
	//measures.dodajNzapisa(measures.stupac1, unesi);
	//measures.obrisiNzapisa(measures.stupac1, unesi);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout<<"Vrijeme je: "<<duration.count()<<"us"<<std::endl;
	
	return 0;
}