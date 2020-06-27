#include "matrix.h"

matrix::matrix()
{
    //ctor
}

matrix::~matrix()
{
    //dtor
}

void matrix::load(const std::string &str)
{
int k=0;
int l=0;
int compteur=0;

std::ifstream file(str.c_str());
if (file.is_open()) {
    std::string line;
    std::string save;
    while (getline(file, line)) {
        save=save+line;
        save=save+'\n';
        /*for(int k=0;k<line.size();k++)
        {
            std::cout<<"k="<<k<<std::endl;
            std::cout<<"l="<<l<<std::endl;

            if(line[k]=='1')
            {   compteur++;
                //mytiles.rect.push_back(mytiles.rect[1]);
                mytiles.rect.push_back(mytiles.bounding);
                //mytiles.draw.push_back(mytiles.sprite[1]);
                mytiles.rect[k].setPosition(16*k,16*l);
                //mytiles.draw[k].setPosition(16*k,16*l);
                //std::cout<< " rentre boucle 1 " << std::endl;
            }

        }*/

        // using printf() in all tests for consistency
        /*printf("%s", line.c_str());
        std::cout<< " k: " << k << " l: " << l << std::endl;*/
        this->k=line.size();
    }
    std::cout << "save: " << save;
    file.close();

    for (int i=0;i<save.size();i++)
    {
        if(save[i]!='\n'){
            if(save[i]=='0')
            {
                vec.push_back(0);
            }
            else if(save[i]=='1')
            {
                vec.push_back(1);
            }
            k++;
        }
        else if(save[i]=='\n')
        {
            k=0;
            l++;
            this->l=l;
        }
        //std::cout<< "k: " << k << " l: "<< l << std::endl;
    }

/*while(mytiles.rect.size()!=compteur)
{
    mytiles.rect.erase(mytiles.rect.end());
}

std::cout << "rect.size: " << mytiles.rect.size() << std::endl;*/

}
}