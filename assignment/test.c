#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    playlist_t* playlist = create_playlist();
    insert_back(playlist->list,4);
    insert_back(playlist->list,3);
    insert_back(playlist->list,1);
    //insert_back(playlist->list,4);
    //insert_back(playlist->list,5);
    display_playlist(playlist);
    k_swap(playlist,1);
    //reverse(playlist);
    display_playlist(playlist);
    return 0;
}