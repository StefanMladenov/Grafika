
// MFCApplication1View.cpp : implementation of the CMFCApplication1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#include "DImage.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define PI 3.14
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: add construction code here
	CString string("Wheel.emf");
	wheel = GetEnhMetaFile(string);

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View drawing

void CMFCApplication1View::OnDraw(CDC* /*DC*/)
{
	CDC *DC = GetDC();

	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;
	//DC->SetMapMode(MM_ANISOTROPIC);
	//DC->SetViewportExt(1920, 1080);
	//DC->SetWindowExt(1920, 1080);

	CRect rect;
	GetClientRect(&rect);

	/*CDC *memDC = new CDC();
	memDC->CreateCompatibleDC(DC);*/
	/*CBitmap bmp;
	bmp.CreateCompatibleBitmap(DC, rect.Width(), rect.Height());
	memDC->SelectObject(&bmp);*/
	int prevMode;

	prevMode = DC->SetGraphicsMode(GM_ADVANCED);
	DC->Rectangle(rect);
	CString string;
	//CreateCombinedRegion(DC);
#pragma region Prvi
	/*Korišćenjem GDI - a implementirati sledeće funkcije :
	a) void DrawBackground(CDC *pDC, CPoint ptCenter, int radius, CString strPicture) koja učitava sliku pod nazivom strPicture i iscrtava je tako da bude vidljiva samo unutar kruga poluprečnika radius sa centrom u tački ptCenter. (10 poena)
	b) void DrawCoin(CDC *pDC, CPoint ptCenter, int radius, CString strText, int fsizeText, CString strCoin, int fsizeCoin, COLORREF clrText) koja iscrtava novčić kružnog oblika poluprečnika radius, bez ispune sa crnom linijom debljine 3. Duž oboda unutar novčića je ispisan tekst strText fontom veličine fsizeText.U centru novčića je ispisana vrednost novčića strCoin podebljanim fontom veličine fsizeCoin.Tekst na novčiću treba da bude boje clrText i ispisan fontom Arial.Smatrati da je font fiksne širine. (30 poena)
	c) void SaveBMP(CString name, CDC *pDC, CPoint ptCenter, int radius), koja novčić iscrtan u pDC kopira u novi memorijski kontekst i snima u datoteku name.*/

	//string = "C:\\Users\\ktg\\Desktop\\coin-icon.bmp";
	//DrawBackground(DC, CPoint(200, 200), 100, string);
	/*DrawCoin(DC, CPoint(400, 400), 100, CString("Narodna banka republike srbije"), 500, CString("50"), 50, RGB(0, 0, 0));
	saveBMP(L"Bicikla", DC, CPoint(400, 400), 100);*/

#pragma endregion

#pragma region April2019

	//Translate(DC, 500, 500);
	//DrawWheel(DC, 70, 50, 10);
	XFORM oldForm,newForm,form;
	//DC->GetWorldTransform(&oldForm);
	//newForm = Translate(200, 200);
	//DC->ModifyWorldTransform(&newForm, MWT_RIGHTMULTIPLY);

	DC->Rectangle(200, 200, 400, 400);
	DC->DrawText(L"Strelica", CRect(200, 200, 400, 400), DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	//DC->SetWorldTransform(&oldForm);
	////newForm = Shear(50, 0, 0);
	////DC->SetWorldTransform(&newForm);
	//DC->SetWorldTransform(&form);
	///*newForm = Shear(50, 0, 0);
	//DC->ModifyWorldTransform(&newForm,MWT_LEFTMULTIPLY);*/
	//form.eM11 = 1;
	//form.eM12 = 0;
	//form.eM21 = 0;
	//form.eM22 = 1;
	//form.eDx = 0;
	//form.eDy = 0;
	//DC->ModifyWorldTransform(&form, MWT_LEFTMULTIPLY);
	//form = Translate(500, 200);
	//DC->ModifyWorldTransform(&form, MWT_RIGHTMULTIPLY);
	//
	//DC->Rectangle(-100,-100,100,100);

	//DC->SetWorldTransform(&oldForm);
	//DrawWP(DC, 70, 50, 10, 800, 60, 100);
	

#pragma endregion 

	//RotateForm = Rotate(45,150,150);
	//DC->SetWorldTransform(&RotateForm);
	//CrtajPravougaonik(DC, 0,0,100,100, 200, 100, 0, 3);
	//memDC->ModifyWorldTransform(&RotateForm, MWT_RIGHTMULTIPLY);

	DC->SetGraphicsMode(prevMode);
	//DC->BitBlt(0, 0, rect.Width(), rect.Height(), memDC, 0, 0, SRCCOPY);
	ReleaseDC(DC);
}


// CMFCApplication1View printing

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

#pragma region Prvi
void CMFCApplication1View::DrawBackground(CDC * pDC, CPoint ptCenter, int radius, CString strPicture)
{
	DImage bg;
	bg.Load(strPicture);
	CRect rect;
	GetClientRect(&rect);
	CRgn Pozadina;
	Pozadina.CreateRectRgn(rect.left, rect.top, rect.right, rect.bottom);
	CRgn Novcic,polygon;
	Novcic.CreateEllipticRgn(ptCenter.x - radius, ptCenter.y - radius, ptCenter.x + radius, ptCenter.y + radius);
	pDC->SelectClipRgn(&Novcic);
	bg.Draw(pDC, CRect(0, 0, bg.Width()/2, bg.Height()/2), CRect(ptCenter.x - radius, ptCenter.y - radius, ((ptCenter.x + radius)/2), (ptCenter.y + radius)/2));
	pDC->SelectClipRgn(&Pozadina);
	Novcic.DeleteObject();
	Pozadina.DeleteObject();
}

void CMFCApplication1View::DrawCoin(CDC * pDC, CPoint ptCenter, int radius, CString strText, int fsizeText, CString strCoin, int fsizeCoin, COLORREF clrText)
{
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	CPen *oldPen = pDC->SelectObject(&newPen);
	CFont sideFont;
	sideFont.CreateFontW(fsizeText, 0, 0, 0, 700, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");// zasto mi se ne menja velicina slova?
	CFont centerFont;
	centerFont.CreateFontW(fsizeCoin, 0, 0, 0, 700, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");
	CRect Novcic(ptCenter.x - radius, ptCenter.y - radius, ptCenter.x + radius, ptCenter.y + radius);
	pDC->Ellipse(ptCenter.x - radius, ptCenter.y - radius, ptCenter.x + radius, ptCenter.y + radius);
	int prevMode = pDC->SetGraphicsMode(GM_ADVANCED);
	XFORM oldForm, newForm;
	bool b = GetWorldTransform(pDC->m_hDC, &oldForm);
	float fact = 360 / strText.GetLength();
	newForm = Translate(-ptCenter.x, -ptCenter.y);
	ModifyWorldTransform(pDC->m_hDC, &newForm, MWT_RIGHTMULTIPLY);
	newForm.eM11 = (float)cos(-PI / 2);
	newForm.eM12 = (float)sin(-PI / 2);
	newForm.eM21 = -(float)sin(-PI / 2);
	newForm.eM22 = (float)cos(-PI / 2);
	newForm.eDx = ptCenter.x;
	newForm.eDy = ptCenter.y;// da li ima bolji nacin za ovo? Da ne bude nested !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	ModifyWorldTransform(pDC->m_hDC, &newForm, MWT_RIGHTMULTIPLY);
	for (int i = 0; i < strText.GetLength(); i++)
	{
		newForm = Translate(-ptCenter.x, -ptCenter.y);
		ModifyWorldTransform(pDC->m_hDC, &newForm, MWT_RIGHTMULTIPLY);
		newForm.eM11 = (float)cos(PI / 180 * fact);
		newForm.eM12 = (float)sin(PI / 180 * fact);
		newForm.eM21 = -(float)sin(PI / 180 * fact);
		newForm.eM22 = (float)cos(PI / 180 * fact);
		newForm.eDx = ptCenter.x;
		newForm.eDy = ptCenter.y;
		ModifyWorldTransform(pDC->m_hDC, &newForm, MWT_RIGHTMULTIPLY);
		pDC->DrawText((CString)strText.GetAt(i), Novcic, DT_CENTER);
	}
	b = pDC->SetWorldTransform(&oldForm);
	SetGraphicsMode(pDC->m_hDC, prevMode);
	//centerFont.CreateFontW(fsizeCoin, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");
	pDC->SelectObject(&centerFont);
	pDC->DrawText(strCoin, Novcic, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	newPen.DeleteObject();
	sideFont.DeleteObject();
	centerFont.DeleteObject();

}

void CMFCApplication1View::saveBMP(CString name, CDC * pDC, CPoint ptCenter, int radius)
{
	CDC* memDC = new CDC();
	memDC->CreateCompatibleDC(pDC);
	CBitmap bmp;
	CRect Novcic(ptCenter.x - radius, ptCenter.y - radius, ptCenter.x + radius, ptCenter.y + radius);
	bmp.CreateCompatibleBitmap(pDC, Novcic.Width(), Novcic.Height());
	memDC->SelectObject(&bmp);
	memDC->BitBlt(0, 0, Novcic.Width(), Novcic.Height(), pDC, Novcic.left, Novcic.top, SRCCOPY);
	DImage img(*memDC->GetCurrentBitmap());
	img.Save(name);
	memDC->DeleteDC();

}
#pragma endregion

#pragma region April2019
//Isrtava tocak gde je r1 spoljasnji pp, r2 unutrasnji, w sirina precke (3 precke popreko - dve pod +-45', jedna pod 90' u odnosu na x
void CMFCApplication1View::DrawWheel(CDC* pDC, double r1, double r2, double w)
{
	int prevMode = pDC->SetGraphicsMode(GM_ADVANCED);
	CPen *oldPen;
	CPen olovka;
	olovka.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	CBrush* staraCetka;
	CBrush sivaCetka;
	CBrush belaCetka;
	sivaCetka.CreateSolidBrush(RGB(128, 128, 128));
	belaCetka.CreateSolidBrush(RGB(255, 255, 255));
	oldPen = pDC->SelectObject(&olovka);
	staraCetka = pDC->SelectObject(&sivaCetka);
	CRect rect;
	GetClientRect(&rect);
	CRgn ellipsa;
	pDC->BeginPath();
	pDC->Ellipse(-r1, -r1, r1, r1);
	pDC->Ellipse(-r2, -r2, r2, r2);
	pDC->EndPath();
	pDC->StrokeAndFillPath();
	//precke

	CRect precka(-r2,-w/2,r2,w/2);
	float angle = 360 / 3;
	float tmpAngle = 90;
	for (int i = 0; i < 3; i++) {
		XFORM form;
		pDC->GetWorldTransform(&form);

		Rotate(pDC, tmpAngle,false);
		pDC->Rectangle(precka);

		pDC->SetWorldTransform(&form);

		tmpAngle += angle;
	}

	
	SetGraphicsMode(pDC->m_hDC, prevMode);
		pDC->SelectObject(staraCetka);
		pDC->SelectObject(oldPen);
		sivaCetka.DeleteObject();
		belaCetka.DeleteObject();
		olovka.DeleteObject();

}
//kosu ravan(trougao - pravougli sa najmanjim uglom alfa) sa nagibom alfa, horizontalna ivica duzine L, i tocak na d od vrha kose ravni
void CMFCApplication1View::DrawWP(CDC* pDC, double r1, double r2, double w, double L, double alpha, double d)
{
	float start_x, start_y;
	start_x = 400;
	start_y = 400;
	float alpha1;
	alpha1 = (alpha * PI) / 180;
	CRect rect;
	GetClientRect(&rect);
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 10, RGB(128, 128, 128));
	CPen *oldPen = pDC->SelectObject(&newPen);
	CBrush newBrush;
	newBrush.CreateHatchBrush(HS_BDIAGONAL, RGB(34, 34, 34));
	CBrush *oldBrush=pDC->SelectObject(&newBrush);
	//racunanje obima i stranica trougla
	float hipotenuza;
	hipotenuza = L / tan(alpha1);
	float obim;
	obim = 2 * r1 * PI;
	float medjuResenje = 100 * d / obim;
	float ugao = 360 * medjuResenje/100;
	float ugao1 = (ugao / 360 * ugao);
	float naspramna;
	naspramna = hipotenuza * (cos(alpha1))/(sin(alpha1));
	float tmpNalegla = d * tan(alpha1);
	float tmpNaspramna = d * (cos(alpha1)) / (sin(alpha1));
	
	// Postolje
	pDC->BeginPath();
	pDC->MoveTo(start_x, start_y);
	pDC->LineTo(start_x+L,start_y);
	pDC->MoveTo(start_x, start_y);
	pDC->LineTo(start_x, start_y - naspramna);
	pDC->LineTo(start_x + L, start_y);
	pDC->EndPath();
	pDC->StrokeAndFillPath();

	pDC->MoveTo(start_x, start_y - naspramna-r1);
	XFORM oldForm,newForm;
	pDC->GetWorldTransform(&oldForm);
	int prevMode = pDC->SetGraphicsMode(GM_ADVANCED);
	Rotate(pDC, ugao1, false);
	Translate(pDC, tmpNalegla + start_x, tmpNaspramna + start_y-naspramna-r1);
	//Rotate(pDC, 90, true);
	pDC->SetWorldTransform(&newForm);
	DrawWheel(pDC, r1, r2, w);
	SetGraphicsMode(pDC->m_hDC,prevMode);
	pDC->SelectObject(&oldBrush);
	pDC->SelectObject(&oldPen);
	DeleteObject(newPen);
	DeleteObject(newBrush);
	DeleteObject(&rect);

	
}
//klasa. Konstruktor treba da na osnovu naziva slike ucita sliku, i u pomocnom DC-ju iscrta sliku ali i njene umanjene kopije(2x manje,4x manje do 1x1 piksel). 
//Dimenzije slike stepen broja 2.
class CMIPMAP
{
	CMIPMAP()
	{
	};
};


void DrawMipMap(CDC* pDC, int x, int y, int size)
{

}
#pragma endregion 

#pragma region CrtanjePrimitiva

void CMFCApplication1View::CrtajPravougaonik(CDC * pDC, int ax, int ay, int bx, int by, int r, int b, int g, int debljinaOlovke)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, debljinaOlovke, RGB(128, 128, 128));
	CPen *oldPen = pDC->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(RGB(r, g, b));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	pDC->Rectangle(ax, ay, bx, by);


	pDC->SelectObject(oldPen);
	DeleteObject(pen);
	pDC->SelectObject(oldBrush);
	DeleteObject(brush);
}

void CMFCApplication1View::CrtajPolygon(CDC * pDC, int ax, int ay, int bx, int by, int r, int b, int g, int debljinaOlovke)
{
	CPen pen;
	pen.CreatePen(PS_DASHDOTDOT, 0, RGB(128, 128, 128));
	CPen *oldPen = pDC->SelectObject(&pen);
	CBrush brush;
	//pDC->SetPolyFillMode(0);
	//brush.CreateHatchBrush(HS_BDIAGONAL, RGB(r, g, b));

	brush.CreateSolidBrush(RGB(r, g, b));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	POINT *p1 = new POINT[4];
	p1[0].x = 4;
	p1[0].y = 4;
	p1[1].x = 40;
	p1[1].y = 4;
	p1[2].x = 40;
	p1[2].y = 40;
	p1[3].x = 4;
	p1[3].y = 40;
	DeleteObject(p1);
	pDC->Polygon(p1, 4);
	pDC->SelectObject(oldPen);
	DeleteObject(pen);
	pDC->SelectObject(oldBrush);
	DeleteObject(brush); delete p1;
}

void CMFCApplication1View::CrtajArc(CDC * pDC, int ax, int ay, int bx, int by, int r, int b, int g, int debljinaOlovke)
{
	CPen pen;
	pen.CreatePen(PS_DASHDOTDOT, 0, RGB(128, 128, 128));
	CPen *oldPen = pDC->SelectObject(&pen);
	POINT *p1 = new POINT[4];
	pDC->SetArcDirection(AD_CLOCKWISE);
	//pDC->SetROP2(R2_NOTXORPEN);
	p1[0].x = 0;
	p1[0].y = 0;
	p1[1].x = 70;
	p1[1].y = 200;
	p1[2].x = 100;
	p1[2].y = 100;
	p1[3].x = 70;
	p1[3].y = 150;
	pDC->Arc(p1[0].x, p1[0].y, p1[1].x, p1[1].y, p1[2].x, p1[2].y, p1[3].x, p1[3].y);
	delete p1;
	pDC->SelectObject(oldPen);
	DeleteObject(pen);
}

void CMFCApplication1View::CrtajPolyBezier(CDC * pDC, int ax, int ay, int bx, int by, int r, int b, int g, int debljinaOlovke)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *oldPen = pDC->SelectObject(&pen);
	POINT *p1 = new POINT[4];
	//pDC->Chord()
	//pDC->MoveTo(20, 20);
	p1[0].x = 50;
	p1[0].y = 50;
	p1[1].x = 50;
	p1[1].y = 100;
	p1[2].x = 100;
	p1[2].y = 100;
	p1[3].x = 160;
	p1[3].y = 60;

	pDC->PolyBezier(p1, 4);
	pDC->MoveTo(50, 50);
	pDC->LineTo(50, 100);
	pDC->MoveTo(160, 60);
	pDC->LineTo(100, 100);
	delete p1;
	pDC->SelectObject(oldPen);
	DeleteObject(pen);


}

void CMFCApplication1View::CrtajElipsu(CDC * pDC, int ax, int ay, int bx, int by, int r, int g, int b, int debljinaOlovke)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, debljinaOlovke, RGB(128, 128, 128));
	CPen *oldPen = pDC->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(RGB(200, 200, 0));
	CBrush *oldBrush = pDC->SelectObject(&brush);

	/*pDC->MoveTo(5, 5);
	pDC->LineTo(150, 150);*/
	pDC->Ellipse(ax, ay, bx, by);

	pDC->SelectObject(oldPen);
	DeleteObject(pen);
}

void CMFCApplication1View::CrtajChord(CDC * pDC, int ax, int ay, int bx, int by, int r, int g, int b, int debljinaOlovke)
{
	CPen pen;
	pen.CreatePen(PS_DASH, 0, RGB(128, 128, 128));
	CPen *oldPen = pDC->SelectObject(&pen);
	POINT *p1 = new POINT[4];
	//pDC->SetArcDirection(AD_CLOCKWISE);
	p1[0].x = 70;
	p1[0].y = 70;
	p1[1].x = 150;
	p1[1].y = 150;
	p1[2].x = 70;
	p1[2].y = 70;
	p1[3].x = 150;
	p1[3].y = 150;
	pDC->Chord(p1[0].x, p1[0].y, p1[1].x, p1[1].y, p1[2].x, p1[2].y, p1[3].x, p1[3].y);
	delete p1;
	pDC->SelectObject(oldPen);
	DeleteObject(pen);

}

void CMFCApplication1View::CrtajPolyPolyline(CDC * pDC, int ax, int ay, int bx, int by, int r, int g, int b, int debljinaOlovke)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(150, 150, 0));
	CPen *oldPen = pDC->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(RGB(50, 200, 200));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	pDC->BeginPath();
	POINT *p1 = new POINT[4];
	p1[0].x = 50;
	p1[0].y = 50;
	p1[1].x = 50;
	p1[1].y = 100;
	p1[2].x = 100;
	p1[2].y = 100;
	p1[3].x = 160;
	p1[3].y = 60;

	pDC->PolyBezier(p1, 4);
	pDC->MoveTo(160, 60);
	/*pDC->LineTo(120, 120);
	pDC->MoveTo(120, 120);
	pDC->LineTo(50, 100);
	pDC->MoveTo(50, 100);*/
	pDC->LineTo(50, 50);
	pDC->EndPath();
	pDC->StrokeAndFillPath();
	pDC->SelectObject(oldPen);

	DeleteObject(pen);
	pDC->SelectObject(oldBrush);
	delete p1;
	DeleteObject(brush);
}

#pragma endregion 

#pragma region Transformacije

XFORM CMFCApplication1View::Translate(CDC * pDC, float x, float y)
{
	XFORM form;
	form.eM11 = 1;
	form.eM12 = 0;
	form.eM21 = 0;
	form.eM22 = 1;
	form.eDx = x;
	form.eDy = y;
	pDC->ModifyWorldTransform(&form, MWT_RIGHTMULTIPLY);
	return XFORM();
}

XFORM CMFCApplication1View::Rotate(CDC * pDC, float angle)
{
	return XFORM();
}

XFORM CMFCApplication1View::Translate(float x, float y)
{
	XFORM form;
	form.eM11 = 1;
	form.eM12 = 0;
	form.eM21 = 0;
	form.eM22 = 1;
	form.eDx = x;
	form.eDy = y;
	return form;

}
XFORM CMFCApplication1View::Shear(float param, float eDx, float eDy)
{
	XFORM form;
	form.eM11 = param;
	form.eM12 = 0;
	form.eM21 = 0;
	form.eM22 = param;
	form.eDx = -eDx;
	form.eDy = -eDy;
	return form;
}

XFORM CMFCApplication1View::Rotate(CDC* pDC, float angle, bool right)
{
	XFORM form;
	//form = Translate(-eDx, -eDy);
	/*form.eM11 = (float)cos(PI * angle / 180);
	form.eM12 = (float)sin(PI  * angle / 180);
	form.eM21 = (float)-sin(PI  * angle / 180);
	form.eM22 = (float)cos(PI * angle / 180);*/
	//ModifyWorldTransform(pDC->m_hDC, &form, MWT_RIGHTMULTIPLY);
	form.eM11 = (float)cos(angle*PI / 180);
	form.eM12 = (float)sin(angle*PI / 180);
	form.eM21 = (float)-sin(angle*PI / 180);
	form.eM22 = (float)cos(angle*PI / 180);
	form.eDx = 0;
	form.eDy = 0;
	if (right)
	pDC->ModifyWorldTransform(&form, MWT_RIGHTMULTIPLY);
	else
	pDC->ModifyWorldTransform(&form, MWT_LEFTMULTIPLY);
	return form;
}

XFORM CMFCApplication1View::Shear(CDC * pDC, float param, float eDx, float eDy)
{
	return XFORM();
}

XFORM CMFCApplication1View::Scale(CDC * pDC, float x, float y)
{
	return XFORM();
}

XFORM CMFCApplication1View::Reflect(CDC * pDC, float x, float y)
{
	return XFORM();
}

XFORM CMFCApplication1View::Scale(float x, float y)
{
	XFORM form;
	form.eM11 = x;
	form.eM12 = 0.0;
	form.eM21 = 0.0;
	form.eM22 = y;
	form.eDx = 0.0;
	form.eDy = 0.0;
	return form;
}

XFORM CMFCApplication1View::Reflect(float x, float y)
{
	XFORM form;
	form.eM11 = x;
	form.eM12 = 0.0;
	form.eM21 = 0.0;
	form.eM22 = y;
	form.eDx = 0.0;
	form.eDy = 0.0;
	return form;
}
#pragma endregion

void CMFCApplication1View::CreateCombinedRegion(CDC * pDC)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255, 128, 0));
	CPen *oldPen = pDC->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(RGB(50, 200, 200));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	CRgn region1, region2, combinedRegion;
	/*CBrush brush1;
	brush.CreateSolidBrush(RGB(0, 100, 100));*/

	//pDC->Ellipse(60, 60, 120, 120);

	//pDC->SelectObject(&brush1);
	//pDC->Rectangle(80, 80, 150, 150);

	region1.CreateEllipticRgn(60, 60, 120, 120);
	region2.CreateRectRgn(80, 80, 150, 150);
	//CombineRgn(combinedRegion, region1, region2, RGN_AND);
	//CombineRgn(combinedRegion, region1, region2, RGN_XOR);
	//CombineRgn(combinedRegion, region1, region2, RGN_OR);
	CombineRgn(combinedRegion, region1, region2, RGN_DIFF);
	//combinedRegion.CombineRgn(&region1, &region2, RGN_AND);
	int rgn = pDC->SelectClipRgn(&combinedRegion);
	pDC->SelectObject(oldPen);
	pen.DeleteObject();
	region1.DeleteObject();
	region2.DeleteObject();
	combinedRegion.DeleteObject();
	pDC->SelectObject(oldBrush);
	//DeleteObject(brush1);
	brush.DeleteObject();
	//brush1.DeleteObject();
}

// CMFCApplication1View diagnostics

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View message handlers
