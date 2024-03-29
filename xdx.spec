# xlog.spec
#
# Copyright (c) 2002-2006 Joop Stakenborg pg4i@amsat.org
#
%define name xdx
%define version 2.4.2
%define release 1

# required items
Name: %{name}
Version: %{version}
Release: %{release}
License: GPL
Group: Applications/Networking
Prefix: /usr
BuildRoot: /var/tmp/%{name}-%{version}
Summary: DX-cluster tcp/ip client for amateur radio
Vendor: Joop Stakenborg <pg4i@amsat.org>
URL: http://www.qsl.net/pg4i/linux/xdx.html
Packager: Joop Stakenborg <pg4i@amsat.org>
Source: %{name}-%{version}.tar.gz

%description
Xdx is a client to connect to a DX-cluster. Dx messages will be displayed
in a list, announcements will go to a text display.

As well as the usual functions, if you have hamlib installed it can control
the radio and set the frequency simply by double clicking a DX-spot
(using rigctl).

WWW: http://www.qsl.net/pg4i/linux/xdx.html
 
%prep
%setup -q

%build
%configure
make

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc README AUTHORS ChangeLog NEWS

/usr/share/locale/nl/LC_MESSAGES/xdx.mo
/usr/share/locale/fr/LC_MESSAGES/xdx.mo
/usr/share/locale/es/LC_MESSAGES/xdx.mo
/usr/share/locale/pl/LC_MESSAGES/xdx.mo
/usr/share/locale/pt/LC_MESSAGES/xdx.mo
/usr/share/xdx/pixmaps/*.png
/usr/share/xdx/pixmaps/*.xcf
/usr/share/xdx/pixmaps/xdx.xpm
/usr/share/xdx/sounds/attention.wav
/usr/share/man/man1/xdx.1.gz
/usr/share/xdx/MANUAL
/usr/share/xdx/MANUAL.es
/usr/share/xdx/MANUAL.fr
/usr/share/xdx/MANUAL.nl
/usr/share/xdx/MANUAL.pl
/usr/share/xdx/wwv.gnuplot
/usr/share/xdx/cty.dat
/usr/bin/xdx
/usr/share/applications/Xdx.desktop

%changelog
* Sun Sep 09 2002 Joop Stakenborg
- Initial spec file
