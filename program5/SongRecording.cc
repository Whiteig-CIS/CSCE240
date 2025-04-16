#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

SongRecording::SongRecording(string title, string primary_artist, int track_length, int num_artists) {
  title_ = title;
  num_artists_ = (num_artists >= 1) ? num_artists : 1;
  track_length_ = (track_length >= 0) ? track_length : 0;
  artists_ = new string[num_artists_];
  artists_[0] = primary_artist;
  for (int i = 1; i < num_artists_; ++i) {
    artists_[i] = "unknown";
  }
}

SongRecording::SongRecording(const SongRecording& other) {
  title_ = other.title_;
  num_artists_ = other.num_artists_;
  track_length_ = other.track_length_;
  artists_ = new string[num_artists_];
  for (int i = 0; i < num_artists_; ++i) {
    artists_[i] = other.artists_[i];
  }
}

SongRecording& SongRecording::operator=(const SongRecording& other) {
  if (this != &other) {
    delete[] artists_;
    title_ = other.title_;
    num_artists_ = other.num_artists_;
    track_length_ = other.track_length_;
    artists_ = new string[num_artists_];
    for (int i = 0; i < num_artists_; ++i) {
      artists_[i] = other.artists_[i];
    }
  }
  return *this;
}

SongRecording::~SongRecording() {
  delete[] artists_;
}

string SongRecording::GetTitle() const {
  return title_;
}

void SongRecording::SetTitle(string title) {
  if (title.length() >= 1) {
    title_ = title;
  }
}

int SongRecording::GetNumArtists() const {
  return num_artists_;
}

void SongRecording::SetNumArtists(int num_artists) {
  if (num_artists < 1) return;

  string* new_artists = new string[num_artists];
  int limit = (num_artists < num_artists_) ? num_artists : num_artists_;
  for (int i = 0; i < limit; ++i) {
    new_artists[i] = artists_[i];
  }
  for (int i = limit; i < num_artists; ++i) {
    new_artists[i] = "unknown";
  }
  delete[] artists_;
  artists_ = new_artists;
  num_artists_ = num_artists;
}

void SongRecording::SetArtist(string artist_name, int index) {
  if (index >= 1 && index <= num_artists_ && artist_name.length() >= 1) {
    artists_[index - 1] = artist_name;
  }
}

string SongRecording::GetArtist(int index) const {
  if (index >= 1 && index <= num_artists_) {
    return artists_[index - 1];
  }
  return "out of bounds";
}

int SongRecording::GetTrackLength() const {
  return track_length_;
}

void SongRecording::SetTrackLength(int track_length) {
  if (track_length >= 0) {
    track_length_ = track_length;
  }
}

}  // namespace csce240_programming_assignment_5