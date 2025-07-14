/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.clinicahospitalar;

import javax.swing.SwingUtilities;
import view.HomeView;

public class ClinicaHospitalar {

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new HomeView().setVisible(true);
        });
    }
}
