#include "config.h"

#include "exceptions.h"
#include "http_get.h"
#include "http.h"

namespace torrent {

Http::Http() :
  m_get(new HttpGet()) {
}

Http::~Http() {
  if (m_get == NULL)
    throw internal_error("Http dtor called on an already destroyed object");

  delete m_get;

  m_get = NULL;
}

void Http::set_url(const std::string& url) {
  m_get->set_url(url);
}

void Http::set_out(std::ostream* out) {
  m_get->set_out(out);
}

const std::string& Http::get_url() const {
  return m_get->get_url();
}

sigc::signal0<void>& Http::signal_done() {
  return m_get->signal_done();
}

// Error code - Http code or errno. 0 if libtorrent specific, see msg.
// Error message
sigc::signal2<void, int, std::string>& Http::signal_failed() {
  return m_get->signal_failed();
}

void Http::start() {
  m_get->start();
}

void Http::close() {
  m_get->close();
}

}

