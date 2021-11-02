#include <bits/stdc++.h>


class StockList
{
public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories){
        std::string result = "";
        if(categories.size()&&lstOfArt.size()){
            for (int i = 0; i < categories.size(); i++){
                if(i!=0) result = result + " - ";
                int total = 0;
                for (int j = 0; j < lstOfArt.size(); j++){
                    char str[lstOfArt[j].length()];
                    strcpy(str, lstOfArt[j].c_str());
                    char *token = std::strtok(str, " ");
                    token = strtok(NULL, " ");
                    if(categories[i][0] == lstOfArt[j][0]) total += atoi(token);
                }
                result = result + "(" + categories[i] + " : " + std::to_string(total) + ")";
            }
        }
        return result;

    }
};

int main(){
    std::vector<std::string> art = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> cd = {"A", "B", "C", "D"};
    std::cout<<StockList::stockSummary(art, cd);
    return 0;
}