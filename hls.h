#ifndef __HLS_DownLoad__hls__
#define __HLS_DownLoad__hls__

#include <stdbool.h>

#define ENC_AES128 0x01
#define ENC_NONE 0x00

struct enc_aes128 {
    bool iv_is_static;
    char iv_value[33];
    char key_value[33];
};

struct hls_media_segment {
    char *url;
    int sequence_number;
    struct enc_aes128 enc_aes;
};

struct hls_media_playlist {
    char *url;
    char *source;
    unsigned int bitrate;
    bool encryption;
    int encryptiontype;
    int count;
    struct hls_media_segment *media_segment;
    struct enc_aes128 enc_aes;
};

struct hls_master_playlist {
    char *url;
    char *source;
    int count;
    struct hls_media_playlist *media_playlist;
};

/**************************************
 * USAGE: Pass the source of a hls file
 * Return values:
 *    -1 - error
 *     0 - master_playlist
 *     1 - media_playlist
 *************************************/
int get_playlist_type(char *source);

/*****************************************************
 * USAGE: Pass a pointer to a master_playlist struct
 * Return values:
 *     0 - success
 *     1 - error
 ****************************************************/
int handle_hls_master_playlist(struct hls_master_playlist *ma);

/*****************************************************
 * USAGE: Pass a pointer to a master_playlist struct
 * Return values:
 *     0 - success
 *     1 - error
 ****************************************************/
int handle_hls_media_playlist(struct hls_media_playlist *me);

int download_hls(struct hls_media_playlist *me);
void print_hls_master_playlist(struct hls_master_playlist *ma);

void media_playlist_cleanup(struct hls_media_playlist *me);
void master_playlist_cleanup(struct hls_master_playlist *ma);
#endif /* defined(__HLS_DownLoad__hls__) */