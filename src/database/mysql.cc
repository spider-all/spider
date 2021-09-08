#include <database/mysql.h>

MySQL::MySQL(const std::string &host) {
  mysql_library_init(0, NULL, NULL);
  db.mysql = mysql_init(NULL);
  if (mysql_real_connect(db.mysql, "127.0.0.1", "root", "8541539655", "test", 3306, NULL, 0) == nullptr) {
    spdlog::error("Database connect with error {}", mysql_error(db.mysql));
  }
}

MySQL::~MySQL() {
  if (db.mysql != nullptr) {
    mysql_close(db.mysql);
  }
  mysql_library_end();
}

int MySQL::initialize() {
  return EXIT_SUCCESS;
}

int MySQL::create_user(User user) { return EXIT_SUCCESS; }

int MySQL::create_org(Org org) { return EXIT_SUCCESS; }

std::vector<std::string> MySQL::list_users() {
  std::vector<std::string> users;
  return users;
}

std::vector<std::string> MySQL::list_orgs() {
  std::vector<std::string> orgs;
  return orgs;
}

int64_t MySQL::count_user() {
  return 0;
}

int64_t MySQL::count_org() {
  return 0;
}

int MySQL::create_emoji(std::vector<Emoji> emojis) {
  return EXIT_SUCCESS;
}

int64_t MySQL::count_emoji() {
  return 0;
}

int64_t MySQL::count_gitignore() {
  return 0;
}

int MySQL::create_gitignore(Gitignore gitignore) {
  return EXIT_SUCCESS;
}

int64_t MySQL::count_license() {
  return 0;
}

int MySQL::create_license(License license) {
  return EXIT_SUCCESS;
}
