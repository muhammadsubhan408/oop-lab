#include <iostream>
using namespace std;

class Robot; //done
class Game;
class Team; //done
class Ball; //done
class Goal; //done

class Robot{
    string name;
    int hits;

    public:
    Robot(string robotName){
        name=robotName;
        hits=0;
    }

    int get_Hits(){
        return hits;
    }
    string get_Name(){
        return name;
    }

    void HitBall(Ball &Ball,const string &direction){
        if (direction == "up") {
            Ball.move(0, 1);
        } else if (direction == "down") {
            Ball.move(0, -1);
        } else if (direction == "left") {
            Ball.move(-1, 0);
        } else if (direction == "right") {
            Ball.move(1, 0);
        }
        hits++;
    }
};


class Ball {
    int x,y;

    public:

    Ball(){
        x=0.0;
        y=0.0;
    }
    void move(int dx, int dy){
        x=x+dy;
        y=y+dy;
    }
    void get_position(){
        cout<<"("<< x << "," << y <<")"<<endl;
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
};

class Goal{
    int x_cord;
    int y_cord;

    public:

    Goal(){
        x_cord=3;
        y_cord=3;
    }

    bool isGoalReached(int ball_x,int ball_y){
        return(ball_x==x_cord && ball_y==y_cord);

    }
};

class Team {
    string teamName;
    Robot *robot;

public:
    Team(string name, Robot *r) : teamName(name), robot(r) {}

    string getTeamName() const { return teamName; }

    Robot* getRobot() const { return robot; }
};

class Game {
    Team *teamOne, *teamTwo;
    Ball ball;
    Goal goal;

public:
    Game(Team *t1, Team *t2) : teamOne(t1), teamTwo(t2), ball(0, 0), goal(3, 3) {}

    void startGame() {
        cout << "Game Started!\n";

        play(teamOne);
        play(teamTwo);

        declareWinner();
    }

    void play(Team *team) {
        cout << "Team " << team->getTeamName() << "'s turn!\n";
        Robot *robot = team->getRobot();
        string directions[] = {"right", "right", "up", "up", "right"}; // Example moves

        for (const string &dir : directions) {
            robot->HitBall(ball, dir);
            auto [ball_X, ball_Y] = ball.get_position();
            cout << robot-> get_Name() << " moved the ball " << dir << " to (" << ball_X << ", " << ball_Y << ")\n";

            if (goal.isGoalReached(ball_X, ball_Y)) {
                cout << "Goal reached by " << robot->get_Name() << " in " << robot->get_Hits() << " hits!\n";
                return;
            }
        }
    }

    void declareWinner() {
        int hitsTeamOne = teamOne->getRobot()->get_Hits();
        int hitsTeamTwo = teamTwo->getRobot()->get_Hits();

        cout << "Team " << teamOne->getTeamName() << " hits: " << hitsTeamOne << endl;
        cout << "Team " << teamTwo->getTeamName() << " hits: " << hitsTeamTwo << endl;

        if (hitsTeamOne < hitsTeamTwo) {
            cout << "Winner: " << teamOne->getTeamName() << endl;
        } else if (hitsTeamTwo < hitsTeamOne) {
            cout << "Winner: " << teamTwo->getTeamName() << endl;
        } 
    }
};


int main(){
    Robot robot1("Alpha"), robot2("Beta");
    Team team1("Red Warriors", &robot1);
    Team team2("Blue Strikers", &robot2);

    Game game(&team1, &team2);
    game.startGame();

    return 0;
}
