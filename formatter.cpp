#include <iostream>
#include <string>
#include <limits> // For input validation

using namespace std;

// Function to validate YES/NO input
bool isYesOrNo(const string& input) {
    return (input == "YES" || input == "NO");
}

// Function to validate a numeric input (for file size)
bool isValidNumericInput(double& input) {
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the bad input
        return false; // Invalid input
    }
    return true; // Valid input
}

int main() {

    string cha, chb, chc, che, chf, chg, chh, chi, chj, chk, chl, chm, chn;
    double chaa, chd;

    cout << "Markdown formatter for listing PS2 game on OPL compatibility list. \nColton Silva 2024" << endl;

    cout << "\nGame ID of your game." << endl;
    cout << "Is this SLUS, SLPS, SLES or something else? ";
    cin >> cha;
    cout << "\nNext, input a Game ID number with this format: XXX.XX: ";
    cin >> chaa;

    cout << "\nEnglish Name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, chb);

    cout << "\nIf your game is released in America or English EU; OR if your computer can't display unicode characters, just type NONE. \nForeign Name: ";
    getline(cin, chc);

    cout << "\nPlease input file size in ISO format in GB, not while in ZIP/7ZIP format." << endl;
    cout << "Size: ";
    cin >> chd;

    // Validate the file size input
    while (!isValidNumericInput(chd)) {
        cout << "Invalid input! Please enter a valid number for the file size: ";
        cin >> chd;
    }

     cout << "Is Japanese title have fan-made english translations?";
    cin >> chh;
    while (!isYesOrNo(chh)) {
        cout << "Invalid input! Please answer with 'YES' or 'NO': ";
        cin >> chh;
    }

    cout << "\nAnswer with YES or NO only." << endl;
    cout << "Need Split? ";
    cin >> che;

    // Validate YES/NO input for Need Split
    while (!isYesOrNo(che)) {
        cout << "Invalid input! Please answer with 'YES' or 'NO': ";
        cin >> che;
    }

    cout << "\nWhat is the game media format? Is it DVD-ISO, CD-BIN, DVD9-ISO or something else? ";
    cin >> chf;

    cout << "\nVNC: YES or NO only: ";
    cin >> chg;
    while (!isYesOrNo(chg)) {
        cout << "Invalid input! Please answer with 'YES' or 'NO': ";
        cin >> chg;
    }
    
 /* cout << "\nIGR: YES or NO only: ";
    cin >> chh;
    while (!isYesOrNo(chh)) {
        cout << "Invalid input! Please answer with 'YES' or 'NO': ";
        cin >> chh;
    }

    cout << "\nPADEMU: YES or NO only: ";
    cin >> chi;
    while (!isYesOrNo(chi)) {
        cout << "Invalid input! Please answer with 'YES' or 'NO': ";
        cin >> chi;
    } */

    cout << "\nGSM: YES or NO only: ";
    cin >> chj;
    while (!isYesOrNo(chj)) {
        cout << "Invalid input! Please answer with 'YES' or 'NO': ";
        cin >> chj;
    }

    cout << "\nCompatible? YES or NO only: ";
    cin >> chk;
    while (!isYesOrNo(chk)) {
        cout << "Invalid input! Please answer with 'YES' or 'NO': ";
        cin >> chk;
    }

    cout << "\nFor Console Model, use this format SCPH-XXXXX. \nConsole Model: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, chl);

    cout << "\nMentioning your GitHub username here is encouraged for easy access to your account.\nYour Name: ";
    getline(cin, chm);

    cout << "\nYour comment about the game. Is there a problem? ";
    getline(cin, chn);

    // Final output formatting
    cout << "\nWell done! Just copy this and paste it into README.md file. Make sure that you follow sorting rules which is the English name must be arranged alphabetically from A to Z" << endl;
    cout << "\n| " << cha << "_" << chaa << " | " << chb << " | " << chc << " | " << chd << " | " << che << " | " << chf << " | " << chg << " | " << chh << " | " << chi << " | " << chj << " | " << chk << " | " << chl << " | " << chm << " | " << chn << endl;

    return 0;
}
