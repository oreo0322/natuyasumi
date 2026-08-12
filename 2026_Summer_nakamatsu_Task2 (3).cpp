#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
    // 定数宣言
    const int CARD = 3;

    const int CARD_NUMBER = 10;

    // 変数の初期化
    int i;
    int hit = 0;

    // プレイヤーとCPUのカードを入れる配列
    int playerCard[CARD];
    int enemyCard[CARD];
    int plyChoice[CARD];
    int emyChoice[CARD];

    bool trunFlag = true;
    bool judgementFlag = false;
    
  　//ランダム関数
    srand((unsigned int)time(NULL));

    for (i = 0; i < CARD; i++)
    {
        playerCard[i] = rand() % CARD_NUMBER;
        enemyCard[i] = rand() % CARD_NUMBER;
    }

    // ゲームタイトルを表示
    cout << "===================   Hit & Blow   ============================" << "\n";

    // ゲームの説明を表示
    cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";

    cout << "あなたの配られてカードは," << "\n";

    for (i = 0; i < CARD; i++)
    {
        cout << i + 1 << "番目" << playerCard[i] << "\n";
    }

    cout << "===================   GAME STRAT   ============================" << "\n";

    // ループ
    while (true)
    {
    
        if (trunFlag)
        {
         
            hit = 0;

           
            cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";

            
            for (i = 0; i < CARD; i++)
            {
             
                while (true)
                {
                   
                    cin >> plyChoice[i];

                 
                    if (0 > plyChoice[i] || 9 < plyChoice[i])
                    {
                    
                        cout << "入力に誤りがあります。再度入力してください。\n";
                    }
                    else
                    {
                
                        break;
                    }
                }
            }

            // カードを比較する
            for (i = 0; i < CARD; i++)
            {
                if (plyChoice[i] == enemyCard[i])
                {
                    cout << "Hit,";

               
                    hit++;
                }
                else
                {
                   
                    cout << "Blow,";
                }
            }

            cout << "\n";

           
            if (hit == 3)
            {
              
                cout << "3Hit!!\n";

                
                judgementFlag = true;

                break;
            }

            cout << "\n";

         
            trunFlag = false;
        }
        else
        {
           
            hit = 0;

        
            cout << "ENEMY TRUN \n";

           
            for (i = 0; i < CARD; i++)
            {
                // 0～9のランダムな数字を生成
                emyChoice[i] = rand() % CARD_NUMBER;

                
                cout << i + 1 << "番目" << emyChoice[i] << "\n";
            }

           
            for (i = 0; i < CARD; i++)
            {
               
                if (emyChoice[i] == playerCard[i])
                {
                    
                    cout << "Hit,";

                  
                    hit++;
                }
                else
                {
                   
                    cout << "Blow,";
                }
            }

            cout << "\n";

         
            if (hit == 3)
            {
              
                cout << "3Hit!!\n";
                break;
            }

            cout << "\n";

         
            trunFlag = true;
        }
    }

    // 判定
    if (judgementFlag)
    {   
        cout << "PLAYER WINNER\n";
    }
    else
    {
        cout << "ENEMY WINNER\n";
    }
    return 0;
}