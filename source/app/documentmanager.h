/*
  * Copyright (C) 2011 Cameron White
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
  
#ifndef APP_DOCUMENTMANAGER_H
#define APP_DOCUMENTMANAGER_H

#include <app/viewoptions.h>
#include <app/caret.h>
#include <boost/optional/optional.hpp>
#include <memory>
#include <score/score.h>
#include <vector>


/// A document is a score that is either associated with a file or unsaved.
class Document
{
public:
    Document();
    Document(const Document &) = delete;
    Document &operator=(const Document &) = delete;

    bool hasFilename() const;
    const std::string &getFilename() const;
    void setFilename(const std::string &filename);

    const Score &getScore() const;
    Score &getScore();

    const ViewOptions &getViewOptions() const { return myViewOptions; }
    ViewOptions &getViewOptions() { return myViewOptions; }

    const Caret &getCaret() const;
    Caret &getCaret();

private:
    boost::optional<std::string> myFilename;
    Score myScore;
    ViewOptions myViewOptions;
    Caret myCaret;
};

/// Class for managing open documents.
class DocumentManager
{
public:
    DocumentManager();

    /// Add a new, blank document.
    Document &addDocument();
    /// Add a new document, and initialize it with a staff, player, etc.
    Document &addDefaultDocument();

    Document &getCurrentDocument();
    Document &getDocument(int i);

    void removeDocument(int index);

    bool hasOpenDocuments() const;
    void setCurrentDocumentIndex(int index);

    int getCurrentDocumentIndex() const;
    size_t getDocumentListSize() const;
    
    /// Returns -1 if the file at filepath is not open, else it returns the index at which the already open file is at
    int findDocument(const std::string& filepath);

private:
    std::vector<std::unique_ptr<Document>> myDocumentList;
    boost::optional<int> myCurrentIndex;
};

#endif
