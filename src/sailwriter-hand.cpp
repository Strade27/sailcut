/*
 * Copyright (C) 1993-2017 Robert & Jeremy Laine
 * See AUTHORS file for a full list of contributors.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "sailwriter-hand.h"
#include <fstream>
#include <QFile>


/** Write sail to TXT "hand" format.
 *
 * @param sail the panel group to write
 * @param filename the file to write to
 */
void CSailHandWriter::write(const CPanelGroup &sail, const QString &filename) const
{
    // open the output file
    ofstream myOut;
    myOut.open(QFile::encodeName(filename), ios::out);
    if (!myOut.is_open())
        throw write_error("CSailWriter::write : unable to write to specified file");

    // write the name of the sail
    myOut << sail.title << endl;

    // TODO : modify code to write actual hand output
    //
    // sail is the sail, loop over its panels
    for (unsigned int i=0; i < sail.size(); i++)
    {
        myOut << "===== CPanel : " << i << " ====" << endl;
        myOut << sail[i].label;
        myOut << "== CSide : left ==" << endl << sail[i].left;
        myOut << "== CSide : top ==" << endl << sail[i].top;
        myOut << "== CSide : right ==" << endl << sail[i].right;
        myOut << "== CSide : bottom ==" << endl << sail[i].bottom;

        if (sail[i].hasHems)
        {
            myOut << "== CSide : cutLeft ==" << endl << sail[i].cutLeft;
            myOut << "== CSide : cutTop ==" << endl << sail[i].cutTop;
            myOut << "== CSide : cutRight ==" << endl << sail[i].cutRight;
            myOut << "== CSide : cutBottom ==" << endl << sail[i].cutBottom;
        }
    }

    myOut.close();
}

