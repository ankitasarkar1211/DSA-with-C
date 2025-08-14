#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    struct Song *next;
};

// Function prototypes
void addSong(struct Song **head, char title[], char artist[]);
void deleteSong(struct Song **head, char title[]);
void displayPlaylist(struct Song *head);
void playPlaylist(struct Song *head);
int searchSong(struct Song *head, char title[]);

// Function to add a song to the playlist
void addSong(struct Song **head, char title[], char artist[]) {
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    if (!newSong) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = NULL;

    if (*head == NULL) {
        *head = newSong;
    } else {
        struct Song *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    printf("Song \"%s\" by %s added successfully.\n", title, artist);
}

// Function to delete a song by title
void deleteSong(struct Song **head, char title[]) {
    if (*head == NULL) {
        printf("Playlist is empty. Nothing to delete.\n");
        return;
    }

    struct Song *temp = *head;
    struct Song *prev = NULL;

    // If head node contains the title
    if (strcmp(temp->title, title) == 0) {
        *head = temp->next;
        free(temp);
        printf("Song \"%s\" deleted successfully.\n", title);
        return;
    }

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song \"%s\" not found in the playlist.\n", title);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Song \"%s\" deleted successfully.\n", title);
}

// Function to display all songs in the playlist
void displayPlaylist(struct Song *head) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("\n--- Playlist ---\n");
    struct Song *temp = head;
    int index = 0;
    while (temp != NULL) {
        printf("%d. \"%s\" by %s\n", ++index, temp->title, temp->artist);
        temp = temp->next;
    }
}

// Function to simulate playing the playlist
void playPlaylist(struct Song *head) {
    if (head == NULL) {
        printf("Playlist is empty. Nothing to play.\n");
        return;
    }
    printf("\n--- Playing Playlist ---\n");
    struct Song *temp = head;
    while (temp != NULL) {
        printf("Playing: \"%s\" by %s 🎵\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

// Function to search for a song by title
int searchSong(struct Song *head, char title[]) {
    struct Song *temp = head;
    int position = 0;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            return position; // Found at this index
        }
        temp = temp->next;
        position++;
    }
    return -1; // Not found
}

// Main function with menu
int main() {
    struct Song *head = NULL; // Playlist head
    int choice;
    char title[100], artist[100];

    while (1) {
        printf("\n--- Music Playlist Menu ---\n");
        printf("1. Add a song\n");
        printf("2. Delete a song\n");
        printf("3. Display playlist\n");
        printf("4. Play playlist\n");
        printf("5. Search for a song\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // remove newline

                printf("Enter artist name: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = '\0';

                addSong(&head, title, artist);
                break;

            case 2:
                printf("Enter song title to delete: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';

                deleteSong(&head, title);
                break;

            case 3:
                displayPlaylist(head);
                break;

            case 4:
                playPlaylist(head);
                break;

            case 5:
                printf("Enter song title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';

                int pos;
                pos = searchSong(head, title);
                if (pos != -1)
                    printf("Song \"%s\" found at position %d.\n", title, pos);
                else
                    printf("Song \"%s\" not found in the playlist.\n", title);
                break;

            case 6:
                printf("Exiting program.\n");
                // Free allocated memory before exit
                while (head != NULL) {
                    struct Song *temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
