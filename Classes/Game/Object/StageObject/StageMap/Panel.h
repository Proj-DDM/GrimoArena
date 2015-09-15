#ifndef PANEL_H
#define PANEL_H
class Panel {
public:
	virtual ~Panel() {}
	virtual void CreatePanel() = 0;
};

#endif