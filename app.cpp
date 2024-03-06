#include <iostream>
using namespace std;

enum enQuestionsLevel{Easy=1,Med=2,Hard=3,Mix=4};

enum enOperationType{Add=1,Sub=2,Mul=3,Div=4,OpMix=5};

struct stQuestion{
    int FirstNumber;
    int SecondNumber;
    char OperationType;
};

struct stGameInfos{
    enQuestionsLevel QuestionsLevel;
    enOperationType OperationType;
    stQuestion Question;
    short Rounds=1;
    short RitghtAnswerTimes=0;
    short WrongAnswerTimes=0;
};

int RandomNumberInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int ReadPostevNumber(string Massge){
    int n=0;
    do
    {
        cout<<Massge;
        cin>>n;
    } while (n<1);
    return n;
}

enQuestionsLevel AskForQuestionsLevel(){
    cout<<"Enter Qestions Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
    short UserAnswer=4;
    cin>>UserAnswer;
    return (enQuestionsLevel) UserAnswer;
}

enOperationType AskForOperationType(){
    cout<<"Enter Operation Type [1]Add, [2]Sub, [3]Div, [4]Mul, [5]Mix ? ";
    short UserAnswer=5;
    cin>>UserAnswer;
    return (enOperationType) UserAnswer;
}

void GetGameInfos(stGameInfos &GameInfos){

    
    GameInfos.Rounds = ReadPostevNumber("How Many Questions Do You Want to answer ? ");
    
    GameInfos.QuestionsLevel = AskForQuestionsLevel();
    
    GameInfos.OperationType = AskForOperationType();

}

void GetFirstAndSecondNumber(stGameInfos &GameInfos){
    switch (GameInfos.QuestionsLevel)
    {
    case enQuestionsLevel::Easy :
        GameInfos.Question.FirstNumber=RandomNumberInRange(1,25);
        GameInfos.Question.SecondNumber=RandomNumberInRange(1,25);
        break;
    
    case enQuestionsLevel::Med :
        GameInfos.Question.FirstNumber=RandomNumberInRange(25,50);
        GameInfos.Question.SecondNumber=RandomNumberInRange(25,50);
        break;

    case enQuestionsLevel::Hard :
        GameInfos.Question.FirstNumber=RandomNumberInRange(50,100);
        GameInfos.Question.SecondNumber=RandomNumberInRange(50,100);
        break;

    case enQuestionsLevel::Mix :
        GameInfos.Question.FirstNumber=RandomNumberInRange(1,100);
        GameInfos.Question.SecondNumber=RandomNumberInRange(1,100);
        break;
    default:
        GameInfos.Question.FirstNumber=RandomNumberInRange(1,30);
        GameInfos.Question.SecondNumber=RandomNumberInRange(1,30);
        break;
    }
}

char GetRandomOperationType(){
    short Num=RandomNumberInRange(1,4);
    switch (Num)
    {
    case 1:
        return '+';
    
    case 2:
        return '-';
    
    case 3:
        return '/';

    case 4:
        return '*';
    default:
        return '+';
    }
}

void GetOperationType(stGameInfos &GameInfos){
    switch (GameInfos.OperationType)
    {
    case  enOperationType::Add :
        GameInfos.Question.OperationType='+';
        break;

    case  enOperationType::Sub :
        GameInfos.Question.OperationType='-';
        break;

    case  enOperationType::Mul :
        GameInfos.Question.OperationType='/';
        break;

    case  enOperationType::Div :
        GameInfos.Question.OperationType='*';
        break;
    case  enOperationType::OpMix :
        GameInfos.Question.OperationType = GetRandomOperationType();
        break;
    default:
        break;
    }
}

void QuestionMaker(stGameInfos &GameInfos){

    GetFirstAndSecondNumber(GameInfos);

    GetOperationType(GameInfos);
}

void PrintQuestion(stGameInfos &GameInfos){
    QuestionMaker(GameInfos);
    cout<<"  "<<GameInfos.Question.FirstNumber<<endl;
    cout<<"  "<<GameInfos.Question.SecondNumber<<endl;
    cout<<"  "<<GameInfos.Question.OperationType<<endl;
    cout<<"---------\n";
}

int ReadAnswer(){
    int UserAnswer=0;
    cin>>UserAnswer;
    return UserAnswer;
}

int Answer(stGameInfos GameInfos){
    int FirstNumber=GameInfos.Question.FirstNumber;
    int SecondNumber=GameInfos.Question.SecondNumber;
    switch (GameInfos.Question.OperationType)
    {
    case '+':
        return FirstNumber + SecondNumber;
    case '-':
        return FirstNumber - SecondNumber;
    case '*':
        return FirstNumber * SecondNumber;
    case '/':
        return FirstNumber / SecondNumber;
    default:
        break;
    }
return FirstNumber + SecondNumber;

}

bool IsTheAnswerRight(stGameInfos GameInfos){

    int TheRightAnswer=Answer(GameInfos);

    int UserAnswer=ReadAnswer();

    return UserAnswer==TheRightAnswer;

}

void PrintQuestionResultsWhenUserIsRight(stGameInfos GameInfos){
    cout<<"_______- Right Answer -_______\n\n\n";
    system("color 2F");
}

void PrintQuestionResultsWhenUserIsWrong(stGameInfos GameInfos){
    cout<<"_______- Wrong Answer -_______\n";
    cout<<"The Right Answer is: "<<Answer(GameInfos)<<endl;
    system("color 4F");
}

void PrintAnswerResults(stGameInfos &GameInfos){
    if(IsTheAnswerRight(GameInfos)){
        GameInfos.RitghtAnswerTimes++;
        PrintQuestionResultsWhenUserIsRight(GameInfos);
    }else{
        GameInfos.WrongAnswerTimes++;
        PrintQuestionResultsWhenUserIsWrong(GameInfos);
    }
}

string GetFinalResults(stGameInfos GameInfos){
    if(GameInfos.RitghtAnswerTimes>=GameInfos.WrongAnswerTimes){
        return "Pass";
    }
        return "Fail";
}

string StringQuestionsLevel(stGameInfos GameInfos){
    switch (GameInfos.QuestionsLevel)
    {
    case enQuestionsLevel::Easy :
        return "Easy";
    case enQuestionsLevel::Med :
        return "Med";
    case enQuestionsLevel::Hard :
        return "Hard";
    case enQuestionsLevel::Mix :
        return "Mix";
    default:
        break;
    }
    return "Mix";
}

string StringOperationType(stGameInfos GameInfos){
    switch (GameInfos.OperationType)
    {
    case enOperationType::Add :
        return "Add";
    case enOperationType::Div :
        return "Div";
    case enOperationType::Mul :
        return "Mul";
    case enOperationType::OpMix :
        return "Mix";
    case enOperationType::Sub :
        return "Sub";
    default:
        break;
    }
    return "Mix";
}

void PrintGameResults(stGameInfos GameInfos){
    cout<<"\n\n_______Game Over_______\n\n";
    cout<<"Final Resutls Is: "<<GetFinalResults(GameInfos)<<endl;;
    cout<<"___________________________\n\n";
    cout<<"Number Of Questions: "<<GameInfos.Rounds<<endl;
    cout<<"Questions Level: "<<StringQuestionsLevel(GameInfos)<<endl;
    cout<<"OP Type: "<<StringOperationType(GameInfos)<<endl;
    cout<<"Your right answer: "<<GameInfos.RitghtAnswerTimes<<endl;
    cout<<"Your wrong answer: "<<GameInfos.WrongAnswerTimes<<endl;
}

void PlayMath(){
    stGameInfos GameInfos;
        GetGameInfos(GameInfos);

        for(int i=0;i<GameInfos.Rounds;i++){
            cout<<"Question["<<i+1<<"]\n";
            PrintQuestion(GameInfos);
            PrintAnswerResults(GameInfos);
        }

        PrintGameResults(GameInfos);
}

void ResetScreen(){
    system("cls");
    system("color 0F");
}

void StartGame(){
    char PlayAgen='y';
    do
    {
        ResetScreen();
        PlayMath();
        cout <<"Do You Want to Play Agin Y/N ? ";
        
        cin >> PlayAgen;

    } while (PlayAgen=='Y'||PlayAgen=='y');
    
}



int main(){

    srand((unsigned)time(NULL));

    
    StartGame();
    
    return 0;
}