class dvbcut: public dvbcutbase {
protected:
  void exportvideo(const char *fmt);
  void addtorecentfiles(const std::list<std::string> &filenames, const std::string &idxfilename=std::string());	// DONE
  void setviewscalefactor(double factor);

  bool eventFilter(QObject *watched, QEvent *e);

  void update_time_display();
  void update_quick_picture_lookup_table();

  int question(const QString & caption, const QString & text);	// DONE
  int critical(const QString & caption, const QString & text);	// DONE

  void make_canonical(std::string &filename);			// DONE
  void make_canonical(std::list<std::string> &filenames);	// DONE

  void addEventListItem(int pic, EventListItem::eventtype type);

  void snapshotSave(std::vector<int> piclist, int range=0, int samples=1);
  int chooseBestPicture(int startpic, int range, int smaples);

protected slots:
  virtual void helpAboutAction_activated();
  virtual void helpContentAction_activated();
	
public:
  ~dvbcut();	// In progress
  dvbcut(QWidget *parent = 0, const char *name = 0, WFlags fl = WType_TopLevel|WDestructiveClose );	// In progress
  void open(std::list<std::string> filenames=std::list<std::string>(), std::string idxfilename=std::string(), std::string expfilename=std::string());	// In progress
  void setbusy(bool b=true);	// DONE
  void batchmode(bool b=true);
  void exportoptions(int format=0, bool bof=true, bool eof=true);
  void addStartStopItems(std::vector<int>, int option=0);
  int getTimePerFrame();

public slots:
  virtual void fileNew();	// DONE: on_fileNewAction_triggered()
  virtual void fileOpen();	// DONE: on_fileOpenAction_triggered()
  virtual void fileSaveAs();
  virtual void fileSave();
  virtual void snapshotSave();
  virtual void chapterSnapshotsSave();
  virtual void fileExport();
  virtual void fileClose();	// DONE: direct connection in UI file
  virtual void editBookmark();
  virtual void editChapter();
  virtual void editStop();
  virtual void editStart();
  virtual void editAutoChapters();
  virtual void editSuggest();
  virtual void editImport();
  virtual void editConvert(int);
  virtual void abouttoshoweditconvert();	// DONE: direct item placement in UI file
  virtual void viewDifference();
  virtual void viewUnscaled();
  virtual void viewNormal();
  virtual void zoomIn();
  virtual void zoomOut();
  virtual void viewFullSize();
  virtual void viewHalfSize();
  virtual void viewQuarterSize();
  virtual void viewCustomSize();
  virtual void playAudio2();
  virtual void playAudio1();
  virtual void playStop();
  virtual void playPlay();
  virtual void jogsliderreleased();	// DONE: on_jogslider_sliderReleased()
  virtual void jogslidervalue(int);	// DONE: on_jogslider_valueChanged()
  virtual void linslidervalue(int);	// In progress: on_linslider_valueChanged()
  virtual void doubleclickedeventlist(QListBoxItem *lbi);
  virtual void eventlistcontextmenu(QListBoxItem *, const QPoint &);
  virtual void mplayer_exited();
  virtual void mplayer_readstdout();
  virtual void clickedgo();
  virtual void clickedgo2();
  virtual void updateimagedisplay();		// DONE
  virtual void audiotrackchosen(int id);	// DONE: on_audiotrackpopup_triggered()
  virtual void loadrecentfile(int id);		// DONE: on_recentfilespopup_triggered()
  virtual void abouttoshowrecentfiles();	// DONE: on_recentfilespopup_aboutToShow()
  };