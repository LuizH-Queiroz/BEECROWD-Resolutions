/*
Rafael is playing a new and exciting RPG game, and just now noticed the existence of something called Guild.
For those who don't know, Guild is about a group of players that get together with a common goal
inside the game, taking advantage of working as a team.

The game that Rafael plays has a GVG system (Guild versus Guild) very disputed, and soon he
realized that he should take some arrangements to do well at these battles.

The GVG system works as follows: the battle happens between two guilds, and wins the guild that has the
greatest amount of points. The number of points that a guild has is given by the sum of the number of
points of the players from the guild. Each player has a number of points, that correspond to
his current level.

Consider that initially, all the players are part of a guild, containing only the player itself.
The union between two guilds makes all the players from both guilds be part of an unique guild,
and the other no longer exists.

Given a list of actions in the game, between them union between two guilds and battles between
two guilds, say the number of times that the guild in which Rafael is part was victorious of a battle.

Input
There will be several test cases. Each test case starts with two integers N and M
(1 ≤ N ≤ 10⁵, 1 ≤ M ≤ 5 * 10⁵), representing the number of players in the game, and the number of
actions in the game, respectively.

Following there will be N integers Pi (1 ≤ Pi ≤ 100), where the i-th number represents the number
of points that the i-th player has, for all 1 ≤ i ≤ N. Rafael is always the player 1.

Following, there will be M lines, containing three integers each, Q, A and B (1 ≤ Q ≤ 2, 1 ≤ A, B ≤ N),
representing the kind of action, and the two guilds involved at such action. If Q is equal to 1,
that means that the guild with the player number A and the guild with the player number B are uniting.
If Q is equal to 2, that means that the guild with the player number A and the guild with the player
number B will battle.

The last test case is indicated when N = M = 0, which should not be processed.

Output
For each test case print one line, containing one integer, representing the number of battles at which
the guild which Rafael is part won a battle. Notice that ties are not considered victories.
*/


#include <iostream>

using namespace std;


enum { RAFAEL = 0, GUILDS_MERGE = 1, GVG_BATTLE = 2 };

struct Player {
    int parent;
    int points;
};


int Guild(int player_index, Player arr[]);
void MergeGuilds(int guildPlayer_1, int guildPlayer_2, Player arr[]);



int main(){
    int num_players, num_actions;

    while (true)
    {
        cin >> num_players >> num_actions;
        if (num_players == 0 && num_actions == 0) break;


        Player players[num_players]; //An index represents a different player, and the 'patriarch'
                                     //of a player represents the Guild to which it belongs.
                                     //It's important to notice that the player's points will change
                                     //when he becomes the representative of a new (merged) Guild,
                                     //and that's because he will then store the sum of points
                                     //in the Guild
        for (int i = 0; i < num_players; i++)
        {
            players[i].parent = i; //Everyone starts in their own Guild
            cin >> players[i].points;
        }


        int victories = 0;
        int player_1, player_2, action;
        for (int i = 0; i < num_actions; i++)
        {
            cin >> action >> player_1 >> player_2;

            switch (action){
                case GUILDS_MERGE:
                    MergeGuilds(player_1-1, player_2-1, players);
                    break;

                case GVG_BATTLE:
                    if (Guild(RAFAEL, players) == Guild(player_1-1, players)
                    and players[Guild(RAFAEL, players)].points > players[Guild(player_2-1, players)].points)
                    {
                        victories++;
                    }
                    else if (Guild(RAFAEL, players) == Guild(player_2-1, players)
                    and players[Guild(RAFAEL, players)].points > players[Guild(player_1-1, players)].points)
                    {
                        victories++;
                    }
                    break;
            }
        }

        cout << victories << endl;
    }



    return 0;
}


int Guild(int player_index, Player arr[]){

    //If the player is the Guild representant, return it
    if (arr[player_index].parent == player_index) return player_index;

    //Otherwise, return the representative and make the current player point to it
    return arr[player_index].parent = Guild(arr[player_index].parent, arr);
}

void MergeGuilds(int guildPlayer_1, int guildPlayer_2, Player arr[]){
    int guild_1 = Guild(guildPlayer_1, arr);
    int guild_2 = Guild(guildPlayer_2, arr);

    //guild_2 receives guild_1 points
    arr[guild_2].points += arr[guild_1].points;

    //guild_1 is now part of guild_2
    arr[guild_1].parent = guild_2;
}