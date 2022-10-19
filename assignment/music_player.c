#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t* create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t* playlist = (playlist_t*) malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t* playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t* create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t* q) // clear the queue q
{	
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t* playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	if(where == -1)
	{
		insert_front(playlist->list,song_id);
	}
	else if(where == -2)
	{
		insert_back(playlist->list,song_id);
	}
	else if(where>-1)
	{
		insert_after(playlist->list,song_id,where);
	}
	playlist->num_songs = playlist->list->size;
}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{
	if(playlist->last_song != NULL && playlist->last_song->data == song_id)
	{
		playlist->last_song = NULL;
	}
	delete_node(playlist->list,song_id);
	playlist->num_songs = playlist->list->size;
	
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
	return search(playlist->list,song_id);
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	playlist->last_song = search(playlist->list,song_id);
	if(playlist->last_song != NULL)
	{
		play_song(song_id);
	}

}

void play_next(playlist_t* playlist, music_queue_t* q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
	if(playlist->list->head == NULL && q->front == NULL)
	{
		return;
	}
	else if(playlist->list->head!= NULL && playlist->last_song == NULL)
	{
		play_song(playlist->list->head->data);
		playlist->last_song = playlist->list->head;
	}
	 else if(q->front == NULL)
	{
		if(playlist->last_song == playlist->list->tail)
		{
			play_song(playlist->list->head->data);
			playlist->last_song = playlist->list->head;
		}
		else
		{
			play_song(playlist->last_song->next->data);
			playlist->last_song = playlist->last_song->next;
		}
	}
	else
	{
		play_song(front(q));
		dequeue(q);
	}
}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{
	if(playlist->list->head == NULL)
	{
		return;
	}
	else if(playlist->last_song == NULL)
	{
		play_song(playlist->list->tail->data);
		playlist->last_song = playlist->list->tail; 
	}
	else if(playlist->last_song->prev == NULL)
	{
		play_song(playlist->list->tail->data);
		playlist->last_song = playlist->list->tail; 
	}
	else
	{
		play_song(playlist->last_song->prev->data);
		playlist->last_song = playlist->last_song->prev;
	}
}

void play_from_queue(music_queue_t* q) // TODO: play a song from the queue
{
	play_song(front(q));
	dequeue(q);
}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q,song_id);
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	if(playlist->list->head == NULL)
	{
		return;
	}
	node_t* previous = NULL;
	node_t* present = playlist->list->head;
	node_t* next = playlist->list->head->next;
	while(next != NULL)
	{
		present->next = previous;
		present->prev = next;
		previous = present;
		present = next;
		next = next->next;
	}
	present->next = previous;
	present->prev = next;

	node_t* temp = playlist->list->head;
	playlist->list->head = playlist->list->tail;
	playlist->list->tail = temp;
}

void k_swap(playlist_t* playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	if(playlist->list->head == NULL)
	{
		return;
	}
	node_t* p = playlist->list->head;
	if(k == 0)
	{
		return;
	}
	else if(k == 1)
	{
		if(playlist->list->head == playlist->list->tail)
		{
			return;
		}
		node_t* node1 = playlist->list->head;
		node_t* node2 = playlist->list->tail;

		playlist->list->head = node1->next;
		playlist->list->head->prev = NULL;
		playlist->list->tail = node1;
		node2->next = node1;
		node1->prev = node2;
		node1->next = NULL;
	}
	else
	{
		int i = 0;
		while(p!=NULL && i<k)
		{
			p = p->next;
			i++;
		}
		if(p == NULL)
		{
			return;
		}
		node_t* q = playlist->list->head;
		while(p != NULL)
		{
			node_t* node1 = q;
			node_t* node2 = p;
			q = q->next;
			p = p->next;

			node_t* temp = node1->next;
			node1->next = node2->next;
			node2->next = temp;
			if(node1->next != NULL)
			{
				node1->next->prev = node1;
			}
			node2->next->prev = node2;

			temp = node1->prev;
			node1->prev = node2->prev;
			node2->prev = temp;
			if(node2->prev != NULL)
			{
				node2->prev->next = node2;
			}
			node1->prev->next = node1;
			if(node1 == playlist->list->head)
			{
				playlist->list->head = node2;
			}
			if(node2 == playlist->list->tail)
			{
				playlist->list->tail = node1;
			}
		}
	}
}

void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
	k_swap(playlist,k);
	reverse(playlist);
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	if(playlist->list->head == NULL)
	{
		return NULL;
	}
	node_t* slow = playlist->list->head;
	node_t* fast = playlist->list->head;
	int loop = 0;
	while(fast!= NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
		{
			loop = 1;
			break;
		}
	}
	if(fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	slow = slow->next;
	int count = 1;
	while(fast != slow)
	{
		slow = slow->next;
		count++;
	}
	slow = playlist->list->head;
	fast = playlist->list->head;
	for(int i = 0;i<count;i++)
	{
		fast = fast->next;
	}
	while(slow!=fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

void display_playlist(playlist_t* p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}

