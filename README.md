# 🕷️ Simple C++ Web Crawler

## 📌 Overview
This is a **basic web crawler written in C++** that:
- Downloads HTML content from a given URL using `wget`
- Extracts links (`href=...`) from the downloaded pages
- Recursively crawls those links up to a specified depth
- Counts word frequencies on each page (ignoring common words)
- Stores visited URLs to prevent re-downloading

It uses:
- A **custom generic hash table** (`Hash`) to store visited URLs and word frequencies
- **Custom file handling** utilities to create and check directories
- **`wget`** (via `system()` calls) for downloading HTML files

---

## 📂 Project Structure
/genericList/components/List.h → Generic linked list implementation
/genericHash/components/hash.h → Generic hash table implementation
/fileHandling/components/fileHandling.h → File handling utilities
crawler.cpp → Main crawler class
main.cpp → Program entry point


---

## ⚙️ Requirements
- **C++ compiler** (g++ recommended, C++11 or newer)
- **wget** installed on your system
- Linux, macOS, or WSL on Windows

---

## 🚀 How to Build & Run

### 1️⃣ Clone the repository
```bash
git clone https://github.com/<your-username>/<repo-name>.git
cd <repo-name>
2️⃣ Compile
Make sure all headers and .cpp files are in the correct folders:

g++ -std=c++11 main.cpp crawler.cpp -o crawler
3️⃣ Run

./crawler <start_url> <target_directory> <max_depth>
Where:

start_url → URL where crawling begins

target_directory → Folder name (inside public/) where HTML will be stored

max_depth → Maximum crawl depth (0 = only start page)

Example:

./crawler "https://example.com" "example_dir" 2
This will:

Create public/example_dir if it doesn’t exist

Download https://example.com

Crawl extracted links up to depth 2

Count most frequent words on each page

-----
### Features
✅ Avoids revisiting the same URL
✅ Skips invalid/unreachable URLs
✅ Limits crawl depth
✅ Saves HTML locally
✅ Finds most frequent word per page

