#ifndef SONG_RECORDING_H
#define SONG_RECORDING_H

#include <string>
#include <iostream>
using std::string;

namespace csce240_programming_assignment_5 {

class SongRecording {
 private:
  string title_;
  string* artists_;
  int num_artists_;
  int track_length_;

 public:
  SongRecording(string title = "untitled",
                string primary_artist = "unknown",
                int track_length = 0,
                int num_artists = 1);

  SongRecording(const SongRecording& other);
  SongRecording& operator=(const SongRecording& other);
  ~SongRecording();

  string GetTitle() const;
  void SetTitle(string title);

  int GetNumArtists() const;
  void SetNumArtists(int num_artists);

  void SetArtist(string artist_name, int index = 1);
  string GetArtist(int index = 1) const;

  int GetTrackLength() const;
  void SetTrackLength(int track_length);
};

}  // namespace csce240_programming_assignment_5

#endif