#include<iostream>
#include <vector>

using namespace std;

const int MATCH  = 1;
const int DIFF  = -1;

struct CARD{
	int Quantity;
	string Type;
	string Color;
	string Filling;
};

int compare_card(CARD first, CARD second){
	return

	(first.Color.compare(second.Color) == 0 && first.Filling.compare(second.Filling) == 0 && first.Quantity == second.Quantity && first.Type.compare(second.Type) == 0) 
	? MATCH : 

	(first.Color.compare(second.Color) != 0 && first.Filling.compare(second.Filling) != 0 && first.Quantity != second.Quantity && first.Type.compare(second.Type) != 0) 
	? DIFF : 0;
}

vector<int> get_differ_set(CARD set[],int i, int j, vector<int> result){

	if(j > 11 || result.size() == 4 ) return result;

	if(compare_card(set[i], set[j]) == DIFF && result.size() < 3){

		if(result.size() < 1) {
			result.push_back(i);
			result.push_back(j);		
		}
		
		if(compare_card(set[result[1]], set[j]) == DIFF && result.size() > 1){
			result.push_back(j);	
		}
	}
	return get_differ_set(set, i, j+1, result);
}

vector<int> get_matching_set(CARD set[],int i, int j, vector<int> result){

	if(j > 11 || result.size() == 3 ) return result;
		

	if(compare_card(set[i], set[j]) == MATCH && result.size() < 3){

		if(result.size() < 1) result.push_back(i);
		result.push_back(j);
	}
		

	return get_matching_set(set, i, j+1, result);
}


vector<vector<int>> get_all_card_set(CARD set[], int i, vector<vector<int>> result){

	if(i > 11 ) return result;


	if(get_matching_set(set, i, i+1, vector<int>() ).size() == 3) 
		result.push_back(get_matching_set(set, i, i+1, vector<int>()  ));


	if(get_differ_set(set, i, i+1, vector<int>() ).size() == 3) 
		result.push_back(get_differ_set(set, i, i+1, vector<int>()  ));
	

	return get_all_card_set(set, i+1, result);
}

int main(){
	CARD set[12] = {
		{2,"Heart","Green","fill in"},
		{3,"Club","Purple","shaded"},
		{1,"Spade","Red","blank"},
		{3,"Heart","Purple","fill in"},
		{2,"Club","Green","shaded"},
		{2,"Spade","Purple","shaded"},
		{2,"Heart","Purple","blank"},
		{2,"Heart","Purple","fill in"},
			{2,"Heart","Purple","blank"},
		{2,"Heart","Purple","blank"},
			{2,"Heart","Purple","blank"},
		{2,"Heart","Purple","blank"},
	};
	
	vector<vector<int>> result ;

	result = get_all_card_set(set, 0, result);
	
	for(int i = 0 ; i < result.size(); i++){
		cout<<i+1<<". "<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<endl;
	}	
	return 0;
}