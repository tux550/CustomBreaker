//
// Created by RodrigoSalad on 11/03/2021.
//

#include "args_interpreter.h"

namespace cb::args_intr{
    args_dict SimpleArgsCollector::operator()(const int &argc, char **argv) {
        // Create return dict
        args_dict return_dict;
        // If no arguments instantly return
        if (argc <= 1) return return_dict;
        // Proces argument by argument
        for (cb::size_t i=1; i<argc; ++i) {
            // Save current arg as string
            args_t c_arg = argv[i];
            // Validate
            validate_flag(c_arg);
            // Get flag type
            auto eq = evalute_type(c_arg);
            // Process flag according to type
            if (eq != args_t::npos){
                process_eqflag(c_arg, eq, return_dict);
            }
            else {
                validate_size(++i, argc);
                process_spflage(c_arg, args_t{argv[i]}, return_dict);
            }
        }
        // Return
        return return_dict;
    }

    void LinkedArgsCollector::operator()(const int &argc, char **argv) {
        // If no arguments instantly return
        if (argc <= 1) return;
        // Proces argument by argument
        for (cb::size_t i=1; i<argc; ++i) {
            // Save current arg as string
            args_t c_arg = argv[i];
            // Validate
            validate_flag(c_arg);
            // Get flag type
            auto eq = evalute_type(c_arg);
            // Process flag according to type
            if (eq != args_t::npos){
                process_eqflag(c_arg, eq);
            }
            else {
                validate_size(++i, argc);
                process_spflage(c_arg, args_t{argv[i]});
            }
        }
    }
}
